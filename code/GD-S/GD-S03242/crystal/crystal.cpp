#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],x,sum,cmp,k,l;
bool b=false;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	while((double)clock()/CLOCKS_PER_SEC<0.90){
	cin>>n>>m;
	l=m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	x=(n+1)/2;
	if(m<10e6) {

		if(n%2==0)
			b=true;
		for(int i=x; i>=1; i--) {
			long long s=a[x]-a[i];
			l-=s;
			if(l<=0)
				break;
			else
				sum++;
		}
		if(b==true) {
			l=m;
			x++;
			for(int i=x; i>=1; i--) {
				long long s=a[x]-a[i];
				l-=s;
				if(l<=0)
					break;
				else
					cmp++;
			}
		}
		sum=max(sum,cmp);
		for(int i=x; i<=n; i++) {
			if(a[x]==a[i])
				sum++;
			else
				break;
		}
		cout<<sum;
	} else
		cout<<n;
	return 0;
	}
}
