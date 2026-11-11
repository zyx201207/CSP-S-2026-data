#include <bits/stdc++.h>
using namespace std;
long long l,n,m,k,a[500005],num[300005],ans[300005];
stack<long long>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]); 
	l=1;
	for(int j=1;j<=n;j++){
		memset(num,0,sizeof(num));
		for(int i=l;i<=n;i++){
			if(num[a[i]]==0){
				num[a[i]]=1;
				q.push(a[i]);
			}else{
				num[a[i]]=0;
				while(!q.empty()){
					k=q.top();
					num[k]=0;
					if(k==a[i]){
						q.pop();
						break;
					}
					q.pop();
				}
				q.push(a[i]);
				num[a[i]]=1;
			}	
		}
		while(!q.empty()){
			k=q.top();
			ans[k]++;
			q.pop();
		}
		l++;	
	}
	for(int i=1;i<=m;i++){
		if(ans[i]!=0) printf("%lld ",ans[i]);
	}
	return 0;
}
