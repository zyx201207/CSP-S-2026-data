#include<bits/stdc++.h>
using namespace std;
bool used[300005];
vector<int>ans;
vector<int>a;
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	ans.resize(m+1,0);
	a.resize(n+1);
	memset(used,0,sizeof(m+1));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(used[a[j]]){
				while(q.top()!=a[j]){
					used[q.top()]=0;
					q.pop();
				}
			}else{
				q.push(a[j]);
				used[a[j]]=1;
			}
		}
		memset(used,0,sizeof(m+1));
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}

	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
} 
