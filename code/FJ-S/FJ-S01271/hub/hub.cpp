#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
bool vi[1000006];
vector<vector<int> > s;
int sh(int x,int y,int len){
	vi[x]=true; 
	int minn=INT_MAX;
	if(x==y){
		return len;
	}
	for(int i=0;i<s[x].size();i++){
		if(vi[x]==false){
			minn=min(minn,sh(s[x][i],y,len+1));
		}
	}
	return minn;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			s[u].push_back(v);
			s[v].push_back(u);
		}
		cout<<sh(1,5,0);
	}
}
/*
这无疑是神圣的
肥美图论 
这…… 
不管了，暴力起手 
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
5 2
1 2
2 3
3 4
4 5
10 3
*/
