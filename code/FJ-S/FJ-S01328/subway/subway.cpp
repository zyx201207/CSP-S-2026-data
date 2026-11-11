#include<bits/stdc++.h>
//i cant know what the word mean. 
//应该绿题 
using namespace std;
int c,n,m,d,q;
const int N=515,M=2500;
long long w[N],k[N],a[N][M],t[N][M]; //
vector<pair<int,int>> ss[N];  //di i ge zhan dian suo duiying de suo you zhan tai,shi jian
int bfs(int s,int f){  //dijstra
	priority_queue<pair<int,int>> q;  //time,station
	unordered_map<int,int> st;
	q.push({0,s});
	st[s]=0;
	while(q.size()){
		auto tt=q.top();
		q.pop();
		if(tt.second==f) return tt.first;
		for(auto i:ss[tt.second]){
			for(int j=1;j<=k[i.first];j++){  //di j ge zhan tai
				if(!st.count(a[i.first][j])||st[a[i.first][j]]>t[i.first][j]+i.second+tt.first){
					q.push({t[i.first][j]+i.second+tt.first,a[i.first][j]});
					st[a[i.first][j]]=t[i.first][j]+i.second+tt.first;   //ju chou wu bi
				}
					
			}
		}
	}
	return -1;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){ //这里把k[i]填成n了 
			cin>>a[i][j]>>t[i][j];
			ss[a[i][j]].push_back({j,t[i][j]});
		}
	}
	while(q--){
		int x=0,y=0;
		cin>>x>>y;
		cout<<w[x]+w[y]+bfs(x,y)<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//我去这道题太臭了
//asdfjkl;sadflk;jasdfl;kjasdfl;kjasdf;lkjasdf;lkjasdf;lkjadsf 
