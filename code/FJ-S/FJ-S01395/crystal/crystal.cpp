#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m;
long long a[500010],b[5010][5010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	a[0]=0;
	for(int i=1;i<n;i++){
		for(int j=n;j>i;j--){
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
		}
		b[i][1]=a[i]-a[i-1];
	}
	b[n][1]=a[n]-a[n-1];
	
	for(int i=3;i<=n;i++){
		for(int j=2;j<i;j++)
			b[i][j]=b[i][1]+b[i-1][j-1];
	}
	for(int i=2;i<=n;i++){
		long long m2=m;
		int j;
		for(j=1;j<=i-1&&m2>=b[i][j];j++){
			m2-=b[i][j];
		}
		ans=max(ans,j);
		
	}
	
	printf("%d",ans);
	return 0;
}
