#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[100005],v[50005],x,f,i,j,ans;
int minn;
void dfs(int x,int s){
	if(s>minn)return ;
	if(x==j){
		minn=min(minn,s);
		v[minn]++;
		return ;
	}
	for(int o=j;o>=x+1;o--){
		if(a[o]-a[x]<=d)dfs(o,s+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>c>>t;
	while(t--){
		f=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		x=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=x)f=0;
		}
		if(f){
			if(d<=x||n-(d/x*2-1)<0)cout<<0<<"\n";
			else{
				cout<<n-(d/x*2-1)<<"\n";
			}
		}
		else if(n>=2000000&&!f){
			x=0;
			for(int i=1;i<=n;i++){
				if(a[n]-a[i]<=d&&a[i]-a[1]<=d){
					x++;
				}
			}
			if(x==2)cout<<1;
			else cout<<0;
		}
		else{
			for(i=1;i<=n-3;i++){
				for(j=i+3;j<=n;j++){
					minn=0x3f;
					memset(v,0,sizeof(v));
					dfs(i,0);
//					cout<<minn<<"\n";
					if(v[minn]==2){
						ans++;
					}
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
