#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
long long a[N],s[N],m,l;
int n,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int i=2,j=1;
	while(j<=n){
		l=s[i]-s[j-1]-(a[i]-a[j-1])*(j-1);
		while(l>m){
			j++;
			l=s[i]-s[j-1]-(a[i]-a[j-1])*(j-1);
		}
		ans=max(ans,i-j+1);
		if(i<n) i++;
		else j++;
	}
	printf("%d",ans);
	return 0;
}
