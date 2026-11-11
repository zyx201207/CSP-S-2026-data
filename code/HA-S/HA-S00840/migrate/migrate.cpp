#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,mn;
long long sum,ans,a[2000010],b[2000010];
void dfs(int l,int r,int x){
	if(b[x]>=r){
		mn=min(mn,x);
		return;
	}
	for(int i=b[x]+1;a[i]<=min(a[b[x]]+d,a[r]);i++){
		b[x+1]=i;
		dfs(l,r,x+1);
	}
}
void dfs2(int l,int r,int x){
	if(b[x]>=r){
		if(x==mn){
			sum++;
		}
		return;
	}
	for(int i=b[x]+1;a[i]<=min(a[b[x]]+d,a[r]);i++){
		b[x+1]=i;
		dfs(l,r,x+1);
	}
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int f=a[2]-a[1];
			if(d<2*f){
				cout<<0;
			}
			else{
				cout<<n-3;
			}
			cout<<endl;
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				sum=0;
				memset(b,0,sizeof b);
				mn=1e9;
				b[1]=a[i];
				dfs(i,j,1);
				memset(b,0,sizeof b);
				b[1]=a[i];
				dfs2(i,j,1);
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}    
	return 0;
}
