#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,z;
long long a[500005],t[505][25],s[505][25];
vector<long long>v[500005];
bool f[505],g[500005];
long long minx=0x3f3f3f3f;
void dfs(int x,int y,long long z){
	for(auto i:v[y]){
		if(f[i]==0){
			f[i]=1;
			for(int j=1;j<=2;j++){
			    if(s[i][j]!=y&&g[s[i][j]]==0){
				    z=z+t[i][3-j]+t[i][j];
				    if(s[i][j]==x){
			            minx=min(minx,z);
			            return ;
		            }else{
		    	        g[s[i][j]]=1;
			            dfs(x,s[i][j],z);
		            }
			    }
		    }
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>z;
			for(int j=1;j<=z;j++){
				cin>>s[i][j]>>t[i][j];
				if(z==2){
					v[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=q;i++){
			minx=0x3f3f3f3f;
			cin>>x>>y;
			g[y]=1;
			dfs(x,y,0);
			cout<<minx+a[x]+a[y]<<endl;
		}
	return 0;
}
