#include<bits/stdc++.h>
using namespace std; 
const int N=5e5+5;
int n;
long long m;
long long a[N];
long long c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=10000){
		long long ma=-1;
		for(i=1;i<n;i++){
			memset(c,0,sizeof(c));
			long long cnt1=0,cnt2=0;
			for(j=1;j<=i;j++){
				c[j]=a[i]-a[j];
				cnt1+=c[j];
			}
			for(j=i+1;j<=n;j++){
				c[j]=a[n]-a[j];
				cnt2+=c[j];
			}
			if(cnt1<=m) ma=max(ma,(long long)i);
			if(cnt2<=m) ma=max(ma,(long long)n-j+1);
		} 
		printf("%lld",ma);
	}else{
		int cnt=0;
		for(i=1;i<=n;i++){
			c[i]=a[n]-a[i];
		}
		for(i=n;i>=1;i--){
			if(m>=c[i]){
				m-=c[i];
				cnt++;
			}
		}
		printf("%d",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
