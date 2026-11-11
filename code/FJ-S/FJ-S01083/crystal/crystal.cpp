#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,ans;
int a[500005];
int s[5005][5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		s[i-1][i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			s[i][j]=s[i][j-1]+(j-i+1)*s[j][j];
			if(s[i][j]<=m&&s[i][j]>ans) ans=j-i+1;
		}
	}
	printf("%lld",ans+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}