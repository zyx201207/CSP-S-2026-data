#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
long long kk[505][M];
int pass[M];
set<int> turn;
bool been[505][M];
int v[M];
struct station{
	int on;
	int at;
	long long time;
};
queue<station>bfs;
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(kk,-1,sizeof(kk));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		int states;
		cin>>states;
		for(int j=0;j<states;j++){
			int ai,ti;
			cin>>ai>>ti;
			kk[i][ai]=ti;
			if(pass[ai]==1) turn.insert(ai);
			pass[ai]++;
		}
	}
	int x,y;
	long long ans=LONG_LONG_MAX;
	while(q--){
		long long sum=0;
		memset(been,false,sizeof(been));
		cin>>x>>y;
		sum+=v[x]+v[y];
		for(int i=1;i<=n;i++){
			if(kk[i][x]!=-1){
				station sta;
				sta.on=i;
				sta.at=x;
				sta.time=sum+kk[i][x];
				bfs.push(sta);
				been[i][x]=true;
			}
		}
		while(!bfs.empty()){
			station st=bfs.front();
			bfs.pop();
			cout<<1;
			if(st.at==y){
				ans=min(ans,st.time+kk[st.on][st.at]);
			}
			for(int i=1;i<=n;i++){
				if(kk[i][st.at]!=-1&&!been[i][st.at]){
					station sta;
					sta.on=i;
					sta.at=st.at;
					sta.time=st.time+kk[st.on][st.at]+kk[i][st.at];
					bfs.push(sta);
					been[i][st.at]=true;
				}
			}
			for(int i=1;i<=M;i++){
				if(kk[st.on][i]!=-1&&(turn.find(i)!=turn.end()||i==y)&&!been[i][st.at]){
					station sta;
					sta.on=i;
					sta.at=st.at;
					sta.time=st.time;
					bfs.push(sta);
					been[i][st.at]=true;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

