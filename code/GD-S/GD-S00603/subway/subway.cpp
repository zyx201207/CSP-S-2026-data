#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[501];
int lst[500];
struct point{
	int val=0;
	vector<int> z;
};
point p[501];
bool visit[501];
stack<int> sum;
void dfs(int x,int y,int exv){
	
	if(x==y){
		sum.push(exv+p[y].val+w[y]);
	}else{
		for(int i=0;i<p[x].z.size();i++){
			if(visit[p[x].z[i]]==0){
				visit[p[x].z[i]]=1;
				dfs(p[x].z[i],y,exv+p[x].val+p[p[x].z[i]].val);
			}
		}
		return;
	}
}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;memset(lst,0,sizeof(lst));
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(lst[1]==0){
				lst[1]=a;
			}
			else{
				for(int q=1;q<=j;q++){
					p[a].z.push_back(lst[q]);
					p[lst[q]].z.push_back(a);
					lst[q]=a;
				}
			}
			p[a].val=t;
		}
	}
	for(int r=1;r<=q;r++){
		int x,y;cin>>x>>y;int mn=2147483647;
		memset(visit,0,sizeof(visit));
		visit[x]=1;
		dfs(x,y,w[x]);
		while(!sum.empty()){
			if(sum.top()!=0){
				mn=min(sum.top(),mn);
			}
			sum.pop();
		}
		cout<<mn<<endl;
	}
	return 0;
}
