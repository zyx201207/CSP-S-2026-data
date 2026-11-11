#include<bits/stdc++.h>
using namespace std;
struct node{
	bool f;
	int t;
}vis[500005];
stack<int> s;
int n,m,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vis[j].f=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]].f){
				while(s.top()!=a[j]){
					vis[s.top()].f=0;
					s.pop();
				}
			}
			s.push(a[j]);
			vis[a[j]].f=1;
		}
		for(int j=1;j<=m;j++){
			if(vis[j].f){
				vis[j].t++;
			}
		}
	}
	for(int i=1;i<m;i++){
		printf("%d ",vis[i].t);
	}
	printf("%d",vis[m].t);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
