#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int f[500005];
int ans[500005];
stack<int >q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){q.push(a[j]);f[a[j]]++;}
			else {
				while(!q.empty()&&q.top()!=a[j]){
					f[q.top()]--;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			int x=q.top(); 
			ans[x]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	
	return 0;
}
