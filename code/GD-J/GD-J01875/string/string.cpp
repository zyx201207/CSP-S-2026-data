#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2*1e5+10;
int n,sum,oy;
struct str{
	int num;
	char c;
}a[maxn];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
	}
	sum/=2;
	int ans=0,chn=0,i=1,j=n;
	char chc;
	bool t;
	while(sum>ans&&i!=j){
		//上一个数无差值时 
		if(chn==0){
			if(a[i].c==a[j].c){
				if(a[i].num>a[j].num){
					chn=a[i].num-a[j].num;
					ans+=a[j].num,j--;
					chc=a[i].c;
					t=0;
				}
				else if(a[i].num<a[j].num){
					chn=a[j].num-a[i].num;
					ans+=a[i].num,i++;
					chc=a[j].c;
					t=1;
				}
				else{
					ans+=a[i].num;
					i++,j--;
				}
			}
			else{
				if(a[i].num>a[j].num){
					chn=a[i].num-a[j].num;
					ans+=a[j].num,oy+=a[j].num,j--;
					chc=a[i].c;
					t=0;
				}
				else if(a[i].num<a[j].num){
					chn=a[j].num-a[i].num;
					ans+=a[i].num,oy+=a[i].num,i++;
					chc=a[j].c;
					t=1;
				}
				else{
					ans+=a[i].num,oy+=a[i].num;
					i++,j--;
				}
			}
		}
		//有差值 
		else{
			if(t==0){
				if(chn>a[j].num){
					ans+=a[j].num;
					if(chc!=a[j].c)    oy+=a[j].num;
					chn=chn-a[j].num;
					j--;
				}
				else if(chn<a[j].num){
					ans+=chn;
					if(chc!=a[j].c)    oy+=chn;
					chn=a[j].num-chn;
					i++,t=1;
					chc=a[j].c;
				}
				else{
					ans+=chn;
					if(chc!=a[j].c)    oy+=chn;
					chn=0;
					i++,j--;
				}
			}
			else{
				if(a[i].num>chn){
					ans+=chn;
					if(chc!=a[i].c)    oy+=chn;
					chn=a[i].num-chn;
					j--,t=0;
					chc=a[i].c;
				}
				else if(a[i].num<chn){
					ans+=a[j].num;
					if(chc!=a[i].c)    oy+=a[i].num;
					chn=chn-a[i].num;
					i++;
				}
				else{
					ans+=chn;
					if(chc!=a[j].c)    oy+=chn;
					chn=0;
					i++,j--;
				}
			}
		}
	}
	cout<<oy;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)    solve();
}
