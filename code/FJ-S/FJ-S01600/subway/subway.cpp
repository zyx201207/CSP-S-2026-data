#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010,INF=1e12+10;
vector<int> g[N],len[N],past[N];
int a[N],w[N],dis[100010],inq[100010];
int times[N][510];
int c,n,m,d,t,k;
queue<int> q;

int pos(int place,int line){
	return place*n+line;
}

void add(int u,int v,int w){
	g[u].push_back(v);
	len[u].push_back(w);
}

int work(int s,int sline,int endd){
	int res=INF;
	int ss=pos(s,sline);
	for(int i=1;i<=pos(m,n);i++){
		dis[i]=INF;
		inq[i]=0;
	}
	q.push(ss);
	dis[ss]=0;
	inq[ss]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i];
			if(dis[y]>dis[x]+len[x][i]){
				dis[y]=dis[x]+len[x][i];
				if(!inq[y]){
					inq[y]=1;
					q.push(y);
				}
			}
		}
	}
	for(int i=0;i<past[endd].size();i++){
		int eline=past[endd][i];
		res=min(res,times[s][sline]+dis[pos(endd,eline)]+times[endd][eline]);
	}
	return res;
}
signed main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>t;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int line=1;line<=n;line++){
		cin>>k;
		for(int id=1;id<=k;id++){
			cin>>a[id];
			cin>>times[a[id]][line];
			past[a[id]].push_back(line);
			if(id>1) add(pos(a[id-1],line),pos(a[id],line),0);	
		}
	}
	for(int id=1;id<=m;id++){
		for(int i=0;i<past[id].size()-1;i++){
			for(int j=i+1;j<past[id].size();j++){
				int line1=past[id][i];
				int line2=past[id][j];
				add(pos(id,line1),pos(id,line2),times[id][line1]+times[id][line2]);
				add(pos(id,line2),pos(id,line1),times[id][line1]+times[id][line2]);
			}
		}
	}
	
	while(t--){
		int s,endd;
		cin>>s>>endd;
		int ans=INF;
		for(int i=0;i<past[s].size();i++){
			int sline=past[s][i];
			ans=min(ans,work(s,sline,endd));
		}
		cout<<ans+w[s]+w[endd]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
