#include <bits/stdc++.h>
using namespace std;
int n,m,x;
int a[500010],cnt[200010];
bool vis[200010];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				s.push(a[j]);
			}
			else{
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			vis[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
