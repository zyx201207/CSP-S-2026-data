#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=-1;
long long a[200010];
//long long f[200010];
//struct stu{
//	int cnt,noww;
//	long long num;
//};
//void bfs(int c,int x,int y){//总个数 数字 到哪里了i
//	queue<stu> q;
//	q.push({c,x,y});
//	while(!q.empty()){
//		stu uu=q.front();
//		q.pop();
////		int dx[3]={a[y+1],x};
////		for(int i=0;i<2;i++){
////			
////		}
//
//	}
//}

void dfs(int c,long long x,int y){//总个数 数字 到哪里了i
	if(c==m){
		ans=max(ans,x);
		return;
	}
	if(y>=n)return;
	if(c!=0){
		int uu=x&a[y+1];
		dfs(c+1,uu,y+1);//y
	    dfs(c,x,y+1);//n
	}
	if(c==0){
		dfs(c+1,a[y+1],y+1);//y
		dfs(c,x,y+1);//n
	}
}

int main(){//dp
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,a[1],0);//选1 
//	dfs(0,?,1);//不选1 
//    int uu=15&7;
//    cout<<uu;
    cout<<ans;
	return 0;
} 