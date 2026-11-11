#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[50005],k[505],a[505][50005],t[505][50005],r[10005][2],ans=1e9+5;
vector<int> mp[50005];
void dfs(int xr,int yr,int r,int sum){
	if(xr==yr){
		ans=min(ans,sum);
		return ;
	}else if(sum>ans){
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=50005;j++){
			if(a[i][j]!=0){
				if(a[i][j]==xr){
					if(i!=r){
						sum=sum+t[i][xr]+t[r][xr];
					}
					dfs(a[i][j],yr,i,sum);
				}
			}
		}
	}
	return ;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][k[i]]>>t[i][k[i]];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>r[i][1]>>r[i][2];
		dfs(r[i][1],r[i][2],1,0);
		cout<<ans+w[r[i][1]]+w[r[i][2]]<<"\n";
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
