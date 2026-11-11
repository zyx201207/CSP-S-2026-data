#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,p,w[50005],t[505][50005],f[1005][1005],x,y,ans;
bool b[50005];
vector<int> v[50005],a[505];
void dfs(int pos,int cnt,int st){
	if(pos==y){
		ans=min(ans,cnt+t[st][pos]);
		return ;
	}
	int tot=cnt;
	b[pos]=1;
	for(auto i:v[pos]){
		if(i!=st){
			tot+=t[i][pos];
			for(auto j:a[i]){
				if(!b[j]){
					if(j==y){
						ans=min(ans,tot+t[i][j]);
						return ;
					}
					dfs(j,tot+t[i][j],i);
				}
				
			}
		}
		else{
			for(auto j:a[i]){
				if(!b[j]){
					dfs(j,tot,i);
				}
			}
		}
	}
	b[pos]=0;
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,aa,tt;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>aa>>tt;
			t[i][aa]=tt;
			v[aa].push_back(i);
			a[i].push_back(aa);
		}	
	}
	while(p--){
		cin>>x>>y;
		ans=1e17;
		if(x==y){
			cout<<0<<'\n';
			continue;
		}
		for(auto i:v[x]){
			dfs(x,t[x][i],i);
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}
