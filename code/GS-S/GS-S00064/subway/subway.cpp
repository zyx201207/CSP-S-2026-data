#include<bits/stdc++.h>
using namespace std;

struct Sh{
	bool li[22];
	int ti[22];
	int pl[22];
	int w;
};

int c,n,m,d,q;
vector< vector<int> > line;
vector<Sh>s;

int dfs(int x,int y){
	for(int i = 1;i<=21;i++){
		if(s[x].li[i]){
			if(s[y].li[i]){
				return (s[x].ti[i]+s[y].ti[i]);
			}else{
				int ansi = 2<<30;
				for(int j = 1;j<=line[i].size();j++){
					if(j == x)continue;
					ansi = min(ansi,s[x].ti[i]+s[line[i][s[x].pl[line[i][j]]]].ti[i]+dfs(line[i][s[x].pl[line[i][j]]],y));
				} 
				return ansi; 
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i = 0;i<=m;i++){
		Sh si;
		s.push_back(si);
	}
	
	for(int i = 0;i<=m;i++){
		vector<int> linei;
		linei.push_back(0);
		line.push_back(linei);
	}
	
	for(int i = 1;i<=m;i++){
		cin>>s[i].w;
	}
	
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			s[a].ti[i] = t;
			s[a].li[i] = true;
			s[a].pl[i] = j;
			line[i].push_back(a);
		}
	}
	vector<int>ans;
	for(int i = 0;i<q;i++){
		int x,y;
		cin>>x>>y;
		ans.push_back(dfs(x,y));
	}
	for(int i = 0;i<q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
} 
