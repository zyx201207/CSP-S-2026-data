#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
bool have[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(have,0,sizeof have);
		stack<int>stk;
		for(int j=i;j<=n;j++){
			if(have[a[j]]){
				while(stk.size()){
					int p=stk.top();stk.pop();
					if(a[p]==a[j])break;
					have[a[p]]=0;
				}
			}
			stk.push(j);
			have[a[j]]=1;
		}
		while(stk.size())ans[a[stk.top()]]++,stk.pop();
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
} 
