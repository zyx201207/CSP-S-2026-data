#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		stack<int>v;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				int f=0;
				while(f!=a[j]){
					f=v.top();
					v.pop();
					b[f]=0;
				}
			}
			v.push(a[j]);
			b[a[j]]=1;
		}
		while(!v.empty()){
			int k=v.top();
			c[k]++;
			v.pop();
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",c[i]);
	return 0;
} 
