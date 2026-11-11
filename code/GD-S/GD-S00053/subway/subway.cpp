#include<bits/stdc++.h>
using namespace std;
struct Station{
	int w;
	int f_line[25];
	long long tl[25];
	int tot;
}station[500010];
struct Line{
	int in;
	long long to[505];
	vector<pair<int,long long>>direct;
	int k;
}line[505];
queue<int> now;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>station[i].w;
		station[i].tot=0;
	}
	int a,t;
	for(int i=1;i<=n;i++){
		line[i].in=0;
		for(int j=0;j<=n+1;j++){
			line[i].to[j]=-1;
		}
		cin>>line[i].k;
		for(int j=0;j<line[i].k;j++){
			cin>>a>>t;
			station[a].f_line[station[a].tot]=i;
			station[a].tl[station[a].tot++]=t; 
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<station[i].tot;j++){
			for(int k=j+1;k<station[i].tot;k++){
				//cout<<" "<<j<<" "<<k<<endl;
				if(j==k){
					continue;
				}
				int x,y;
				x=station[i].f_line[j];
				y=station[i].f_line[k];
				if(line[x].to[y]==-1){
					line[x].to[y]=station[i].tl[j]+station[i].tl[k];
					line[y].to[x]=station[i].tl[j]+station[i].tl[k];
				}
				else{
					line[x].to[y]=min(line[x].to[y],station[i].tl[j]+station[i].tl[k]);
					line[y].to[x]=line[x].to[y];
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<line[i].to[j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			if(line[i].to[j]!=-1){
				line[i].direct.push_back({j,line[i].to[j]});
				line[i].to[j]=-1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int th;
		while(!now.empty()){
			now.pop();
		}
		now.push(i);
		line[i].to[i]=0;
		line[i].in=1;
		while(!now.empty()){
			th=now.front();
			now.pop();
			line[th].in--;
			if(line[th].in>0){
				continue;
			}
			for(const auto t:line[th].direct){
				//cout<<i<<" "<<th<<" "<<t.first<<" "<<line[i].to[th]+t.second<<" "<<line[i].to[t.first]<<endl;
				if(line[i].to[th]+t.second<line[i].to[t.first] or line[i].to[t.first]==-1){
					line[i].to[t.first]=line[i].to[th]+t.second;
					now.push(t.first);
					line[t.first].in++;
				}
			}
		}
	}
	int x,y;
	long long ans;
	for(int i=0;i<q;i++){
		cin>>x>>y;
		ans=-1;
		for(int j=0;j<station[x].tot;j++){
			for(int k=0;k<station[y].tot;k++){
				if(ans==-1 or line[station[x].f_line[j]].to[station[y].f_line[k]]+station[x].tl[j]+station[y].tl[k]+station[x].w+station[y].w<ans){
					ans=line[station[x].f_line[j]].to[station[y].f_line[k]]+station[x].tl[j]+station[y].tl[k]+station[x].w+station[y].w;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
