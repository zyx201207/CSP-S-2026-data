#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int a[500005],b[500005],sum[300005],c[300005];
bool x[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(sum[a[i]]!=0){
			b[i]=sum[a[i]];
		}
		sum[a[i]]=i;
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			if(b[j]>=i&&x[b[j]]==1){
				for(int k=b[j]+1;k<j;k++)x[a[k]]=0;
			}
			x[a[j]]=1;
		}
		for(int j=i;j<=n;j++)c[a[j]]+=x[a[j]];
	}
	c[a[n]]++;
	for(int i=1;i<=m;i++)printf("%d ",min(n,c[i]));
	fclose(stdin);fclose(stdout);
	return 0;
} 
