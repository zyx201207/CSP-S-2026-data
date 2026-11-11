#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010],l=1,k;
int f(int x){
	for(int i=x;i<=n;i++){
		for(int j=n;j>=i+1;j++){
			if(a[i]==a[j]){
				return f(j);
			}
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i+1;j--){
			if(a[i]==a[j]){
				if(a[f(j)]!=a[j])ans[a[i]]++;
				for(int q=f(j);q<=n;q++)ans[a[q]]++;
				k=1;
			}
			if(k==1)break;
		}
		if(k==0)for(int q=i;q<=n;q++)ans[a[q]]++;
		k=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";                
	return 0;
}
