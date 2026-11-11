//准考证:GZ-J00520 学校:龙里县民族完全中学 姓名:李玮辰 
#include<bits/stdc++.h>
using namespace std;
int m,n;
int v[10000];
int maxx=INT_MIN;
void dfs(int g,int x,int start,int r){
	if(g>n){
		maxx=max(maxx,r);
		return;
	}
	for(int i=start;i<m;i++){
		dfs(g,0,i+1,r);
		dfs(g+1,1,i+1,(r&v[i]));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>v[i];
	}
	dfs(1,0,0,-1);
	cout<<maxx;
	return 0;
}
