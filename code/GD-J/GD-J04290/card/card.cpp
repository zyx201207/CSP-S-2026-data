#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005],k[300005];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n>=5000){
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof f);
			for(int j=i;j<=n;j++){
				if(a[j]!=a[j-1]||j==i){
					q.push(a[j]);
				}
			}
			while(!q.empty()){
				k[q.top()]++;
				q.pop();
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof f);
			for(int j=i;j<=n;j++){
				if(f[a[j]]==0){
					q.push(a[j]);
					f[a[j]]=1;
				}else{
					while(!q.empty()){
						if(q.top()!=a[j]){
							f[q.top()]--; 
							q.pop();	
						}else break;
					}
				}
			}
			while(!q.empty()){
				k[q.top()]++;
				q.pop();
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(k[i]!=0)printf("%d ",k[i]);	
	}
	
	
	return 0;
}
