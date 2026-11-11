#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t,maxx,ans,mm;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);mm=m;
	for(register int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+1+n);
	for(register int i=1;i<=n;i++){
		for(register int j=i;j>=1;j--){
			t=a[i]-a[j];
			if(t>m)break;
			else{
				m-=t;
				ans++;
			}
		}
		maxx=max(maxx,ans);ans=0;m=mm;
	}printf("%lld",maxx);
	return 0;
}
