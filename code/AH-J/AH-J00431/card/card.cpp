#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010],jl[300010],cnt[300010];
stack<int>s;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		fill(jl,jl+n+1,0);
		for(int j=i;j<=n;j++){
			if(!jl[a[j]])s.push(a[j]),jl[a[j]]=1;
			else{
				while(s.top()!=a[j]){
					jl[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
	return 0;
}
