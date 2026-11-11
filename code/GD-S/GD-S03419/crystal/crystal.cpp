#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],b[5005][5005];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				b[i][j]=a[i]-a[j];
		int e=0;
		for(int i=2;i<=n;i++){
			int d=0;bool f=false;
			for(int j=i-1;j>=1&&!f;j--){
				d+=b[i][j];
				if(j==1&&d<=m)
					if(i>e)
						e=i;
				if(d>m){
					if(i-j>e)e=i-j;
					f=true;
				}
			}
		}
		ans+=e;
	}
	else{
		ans=1;
		for(int i=1;i<n;i++)
			if((long long)(i*(i+1))*(a[2]-a[1])/2<=m)ans++;
	}
	printf("%d\n",ans);
	return 0;
}
