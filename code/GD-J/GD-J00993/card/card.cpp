#include<bits/stdc++.h>
using namespace std;
int n,m,a[300001],ans[300001];
bool p[300001];
stack<int> ta;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(p[a[j]]==1){
				while(!ta.empty()&&ta.top()!=a[j]){
					p[ta.top()]=0;
					ta.pop();
				}
			}
			else{
				p[a[j]]=1;
				ta.push(a[j]);
			}
		}
		while(!ta.empty()) ta.pop();
			for(int i=1;i<=m;i++){
				if(p[i]==1) ans[i]++;
				p[i]=0;
			}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
