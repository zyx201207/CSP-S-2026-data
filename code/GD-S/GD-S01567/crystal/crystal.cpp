#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum;
bool b=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
			sum=0;
			for(long long j=1;j<=i;j++){
				long long ls=a[i]-a[j];
				sum+=ls;
				if(sum>=m&&a[i+1]!=a[i]){
					if(sum>m) cout<<i-1;
					else cout<<i;
					return 0;
				}
			}
	}
	return 0;
}
