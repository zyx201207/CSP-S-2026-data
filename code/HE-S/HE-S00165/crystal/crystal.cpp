#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	int c = a[2]-a[1];
	bool b = true;
	for(int i=1;i<n;i++)
		if (a[i+1]-a[i]!=c)
			b = false;
	if(b){
		int x = c,sum=1;
		for(int i=1;i<=n;i++){
			m-=x;
			if(m>0)
				x+=c,sum++;
			else
				break;
		}
		printf("%d",sum);
		return 0;
	}
	sort(a+1,a+n+1);
	int maxn = -1;
	for(int i=n;i>=1;i--){
		int x = m;
		int sum=1;
		for(int j=i-1;j>=1;j--){
			if(m>=a[i]-a[j])
				m-=a[i]-a[j];
			else
				break;
			sum++;
		}
		maxn = max(maxn,sum);
		m = x;
	}
	printf("%d",maxn);
}
