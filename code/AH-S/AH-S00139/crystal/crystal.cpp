#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],p=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(!(a[i]==a[i-1]&&i!=1)){
			p=0;
		}
	}
	if(p==1)cout<<n<<endl;
	sort(a+1,a+n+1);
	long long mid=0;
	if(n/2*2==n)mid=a[n/2];
	else mid=a[n/2+1];
	for(int i=1;i<=n;i++){
		a[i]=abs(a[i]-mid);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]<=m){
			m-=a[i];
			ans++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
