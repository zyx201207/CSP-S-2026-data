#include<bits/stdc++.h>
using namespace std;
int c,t;
long long 	 n,d;
long long a[10001];
struct node{
	int u;
	int next;
}tree[10001];
int maxn[10001],index=0;
int b[10001],ans[10001];
int sum=0;
void add(int cu,int to){
	index++;
	tree[index].u=to;tree[index].next =maxn[cu];
	maxn[cu]=index;
	return;
}
void bfs(int to){
	priority_queue<pair<int,int>> q;
	q.push({0,to});b[to]=0;
	while(q.size()){
		pair<int,int> p=q.top();q.pop();
		int x=p.second,time=p.first;
		for(int i=maxn[x];i>0;i=tree[i].next ){
			int cu=tree[i].u;
			if(cu <x||(b[cu]<time+1&&b[cu]!=-1)) continue;
			if(b[cu ]==time+1) ans[cu]++;
			else{
				b[cu]=time+1;ans[cu]=0;
			} 
			q.push({b[cu],cu} );
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==1) sum++;
		ans[i]=0;
	}
		
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		sum=0;
		memset(maxn,0,sizeof(maxn));
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		index=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])<=d){
					add(i,j);add(j,i);
				} 
				else j=n+1;
			}	
		for(int i=1;i<=n;i++){
			memset(b,-1,sizeof(b));
			bfs(i);
		}
		
		cout<<sum<<endl;	
	}
	return 0;
}
