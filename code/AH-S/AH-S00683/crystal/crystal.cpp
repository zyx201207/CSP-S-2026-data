#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,s=1;
	for(int i=2;i<=n;i++){
		m=m-(a[i]-a[i-1])*(i-1-l+1);
		while(m<0){
			m=m+a[i]-a[l];
			l++;
		}
		s=max(s,i-l+1);
	}
	printf("%d",s);
	return 0;
}
