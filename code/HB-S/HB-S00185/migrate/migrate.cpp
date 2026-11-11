#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,t;
int dis[10005];
int n,d;
int a[10005];
int ans[10005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int js=0;
		for(int i=1;i<=n;i++){
			memset(ans,0,sizeof(ans));
			int cnt=1;
			dis[i]=0;
			for(int j=i;j<=n;j++) dis[j]=a[j]-a[i];
			for(int j=i+1;j<=n;j++){
				if(a[i]+d>=a[j]){
					dis[j]=1;
					cnt++;
				}
			}
			for(int j=cnt+i;j<=n;j++){
				if(a[j-1]+d<a[j]) break;
				for(int k=i;k<=j;k++){
					if(a[k]+d>=a[j]){
						if(dis[k]+1<dis[j]) ans[j]=0;
						if(dis[j]==dis[k]+1){
//							cout<<"i="<<i<<" "<<"j="<<j<<" "<<"k="<<k<<endl;
//							cout<<"dis[j]"<<dis[j]<<"  dis[k]+1="<<dis[k]<<"+1="<<dis[k]+1<<endl;
							ans[j]++;
						} 
						else dis[j]=min(dis[j],dis[k]+1);
					}
				}
			}
			for(int j=cnt+1;j<=n;j++){
				if(ans[j]==1) js++;
			}
		}
		cout<<js<<'\n';
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/
