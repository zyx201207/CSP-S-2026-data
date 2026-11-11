#include<bits/stdc++.h>
using namespace std;

const long long I=5e5+1;
long long w[I];

struct Sub{
	int i;
	int a;
	int t;
};
Sub s[I];

vector<vector<Sub>> v;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			s[j].i=i;
			cin>>s[j].a;
			cin>>s[j].t;
			if(j>1){
				v[s[j-1].a].push_back(s[j]);
				v[s[j].a].push_back(s[j-1]);
			}
		}
	}
	while(q--){
		int ans=0;
		int x,y;
		cin>>x>>y;
		ans+=w[x]+=w[y];
		for(int i=0;i<v[x].size();i++){
			if(v[x][i].a==y){
				ans+=v[x][i].t;
				for(int j=0;j<v[v[x][i].a].size();j++){
					if(v[v[x][i].a][j].a==x){
						ans+=v[v[x][i].a][j].t;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
