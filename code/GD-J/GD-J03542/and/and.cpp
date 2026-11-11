#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[200005],ans,Max;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		f[i]=a[i];
		Max=max(Max,a[i]);
	}
	if(n==m){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
			printf("%d ",ans);
		}
		return 0;
	}
	if(n==1) cout<<Max;
	for(int i=2;i<=m;i++){
		for(int j=i-1;j<n;j++){
			int now=f[j];
			f[j]=0;
			for(int t=0;t<j;t++){
				f[j]=max(f[j],now&a[t]);
			}
		}
	}
	for(int i=m-1;i<n;i++){
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
	return 0; 
}
