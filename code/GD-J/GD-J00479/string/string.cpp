#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,a[N];
char c[N]; 
struct node{
	int cnt;
	char ch;
}b[N];
int tot,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int cur=0,mid=0,pos;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mid+=a[i];
		if(i>1&&c[i]!=c[i-1]){
			b[++tot]={cur,c[i-1]};
			cur=0;
		}
		cur+=a[i];
	}
	if(cur>0) b[++tot]={cur,c[n]},cur=0;
	mid=(mid/2)+(mid&1);
	for(int i=1;i<=tot;i++){
		cur+=b[i].cnt;
		if(cur>=mid){
			pos=i;
			break;
		} 
	}
	int l=1,r=tot;
	while(l<r){
		if(l==r) break;
		if(b[l].ch==b[r].ch){
			if(b[l].cnt>b[r].cnt){
				b[l].cnt-=b[r].cnt;
				b[r].cnt=0;
				r--;
			}
			else{
				b[r].cnt-=b[l].cnt;
				b[l].cnt=0;
				l++;
				if(b[r].cnt==0) r--;
			}
		}
		else{
			if(b[l].cnt>b[r].cnt){
				ans+=b[r].cnt;
				b[l].cnt-=b[r].cnt;
				b[r].cnt=0;
				r--;
			}
			else{
				ans+=b[l].cnt;
				b[r].cnt-=b[l].cnt;
				b[l].cnt=0;
				l++;
				if(b[r].cnt==0) r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
1 c
*/
