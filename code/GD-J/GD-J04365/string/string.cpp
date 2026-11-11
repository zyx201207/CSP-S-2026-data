#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+50; 
struct node{
	int cnt;
	string s;
}a[N];
int aaaa;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].s;
		aaaa+=a[i].cnt;
	}
	cout<<aaaa<<'\n';
	string last;
	int flag=0;int lastc=0;//f=1是前面，f=2是后面
	int ans=0; 
	for(int i=1;i<=(n+1)/2;i++){//缺遗留问题 
		lastc=abs(lastc);
		if(lastc){
			if(n-i+1==i){
				if(lastc==a[i].cnt)ans+=lastc;
				else if(lastc>a[i].cnt){
					ans+=a[i].cnt;
				}else{
					ans+=lastc;
				}
			}
			if(flag==1){
				if(last!=a[n-i+1].s){
					a[i].cnt+=lastc; 
				}else{
					a[n-i+1].cnt-=lastc;
				}
			}
			else{
				if(last!=a[i].s){
					a[n-i+1].cnt+=lastc; 
				}else{
					a[i].cnt-=lastc;
				}
			}
		}
		lastc=0;
		flag=0;
		if(a[i].s==a[n-i+1].s){
			if(a[i].cnt==a[n-i+1].cnt)continue;
			else if(a[i].cnt<a[n-i+1].cnt){
				lastc=a[n-i+1].cnt-a[i].cnt;
				flag=2;
				last=a[n-i+1].s;
			}
			else{
				lastc=a[i].cnt-a[n-i+1].cnt;
				flag=1;
				last=a[i].s;
			}
		}else{
			if(a[i].cnt==a[n-i+1].cnt){
				//cout<<1<<" "<<ans<<'\n';
				ans+=a[i].cnt;
			}
			else if(a[i].cnt<a[n-i+1].cnt){
				lastc=a[n-i+1].cnt-a[i].cnt ;
				ans+=a[i].cnt;
				flag=2;
				last=a[n-i+1].s;
			}
			else{
				lastc=a[i].cnt-a[n-i+1].cnt;
				ans+=a[n-i+1].cnt;
				flag=1;
				last=a[i].s;
			}
		}
	}
	cout<<ans;
	return 0;
}/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
