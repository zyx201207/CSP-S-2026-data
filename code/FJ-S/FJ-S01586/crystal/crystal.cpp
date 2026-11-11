#include<bits/stdc++.h>
using namespace std;

#define N 500001

long long a[N],d[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
//	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>a[i];
//		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		d[i]=a[i]-a[i-1];
	long long c=d[2];
	for(int i=1,j=2;i<=n&&j<=n;i++){
		while(j<n&&c+(j-i+1)*d[j+1]<=m)
			c+=(j-i+1)*d[++j];
		ans=max(ans,j-i+1);
		c-=a[j]-a[i];
	}
	cout<<ans<<'\n';
//	printf("%d\n",ans);
	return 0;
}
