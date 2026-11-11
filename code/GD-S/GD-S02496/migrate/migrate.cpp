#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,mn,sum,t[2000005];
long long a[2000005];
void dfs(int k,int l,int r){
	if(k>mn) return;
	if(l==r){
		if(k<mn){
			mn=k;
			sum=1;
		}else if(k==mn){
			sum++;
		}
		return;
	}
	for(int i=1;l+i<=r;i++){
		if(a[l+i]-a[l]<=d){
			dfs(k+1,l+i,r);
		}else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		if(n<=3){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int l=1;l<=n;l++)
			for(int r=l+3;r<=n;r++){
				mn=2000005,sum=0;
				dfs(0,l,r);
				if(sum==2) ans++;
			}
		cout<<ans<<'\n';
	}
}
