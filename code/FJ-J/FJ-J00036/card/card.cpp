#include<bits/stdc++.h>
using namespace std;
int n,m,l,ans[30000],b[200000],a[20000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int t=1;t<=n;t++){
		vector<bool>v(m+5,0);
		vector<int>c(20000,0);
		for(int i=t;i<=n;i++){
			if(v[a[i]]){
				while(c[l]!=a[i]){
					v[c[l]]=0;
					c[l--]=0;
					
					if(c[l]==a[i])break;
				}
			}else{
				v[a[i]]=1;
				c[++l]=a[i];
			}
		}
		for(int i=1;i<=l;i++)ans[c[i]]++;
		l=1;
		
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
