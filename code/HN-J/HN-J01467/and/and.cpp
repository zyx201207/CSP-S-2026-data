#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int unsigned long long
long long a[N];
const int X=1;
//int cnt[50];
bool cmp(int x,int y){
	return x>y;
}
int n,m;
bool vis[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n){
		int ans=(X<<34)-1;
		for(int i=1;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	bool f=true;
	int ans=0,res=X<<31;
	for(int i=32;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				if((a[j]>>(i-1))&1){
					cnt++;
				}
				else{
					vis[j]=true;
				}
			}
		}
		if(cnt>=m){
			ans+=res;
			f=false;
		}
		else if(f){
			for(int j=1;j<=n;j++)vis[j]=false;
		}
		res>>=1;
	} 
	cout<<ans;
	return 0;
}
