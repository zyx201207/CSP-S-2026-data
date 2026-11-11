#include<bits/stdc++.h>
#define int long long
using namespace std;
struct asd{
	vector<int> line,t;
}sta[500005];
int w[500005];
vector<int> line[505];
int line_t[505];
int find(int s,int e){
	for(int i=0;i<sta[e].line.size();i++){
		if(sta[e].line[i]==s)return sta[e].t[i];		
	}
	return -1;
}
int dfs(int s,int e){
//	if(line_t[s])
	int o=find(s,e);
	if(o!=-1){
		return o;
	}
	int mint=1e9;
	for(int i=0;i<line[s].size();i++){
		if(sta[line[s][i]].line.size()>=2){
			for(int ii=0;ii<sta[line[s][i]].line.size();ii++){
				if(sta[line[s][i]].line[ii]==s)continue;
				mint=min(mint,dfs(sta[line[s][i]].line[ii],e)+sta[line[s][i]].t[ii]+find(s,line[s][i]));
			}
		}
	}
	return mint;
}
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int ii=0;ii<k;ii++){
			int a,b;
			cin>>a>>b;
			line[i].push_back(a);
			sta[a].line.push_back(i);
			sta[a].t.push_back(b);
//			if(sta[a].line.size()>=2){
//				for(int iii=0;iii<sta[a].line.size()-1;iii++){
//					line_t[sta[a].line[iii]][i]=sta[a].t[iii]+b;
//					line_t[i][sta[a].line[iii]]=sta[a].t[iii]+b;
//				}
//			}
		}
	}
	while(q--){
		int s,e,ans=1e9;;
		cin>>s>>e;
		for(int i=0;i<sta[s].line.size();i++){
			ans=min(ans,dfs(sta[s].line[i],e)+sta[s].t[i]);
			//
		}
		cout<<ans+w[s]+w[e]<<endl;
		//
	}
//	cout<<dfs(1,3)+w[1]+w[3]+sta[1].t[0]<<" "<<sta[line[1][1]].t[1]<<" "<<dfs(2,3)<<" "<<find(2,3);
}
