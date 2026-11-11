#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+1000;
long long n,m,a[maxn],sum=1,i=1,j,g=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		g=0;
		for(j=i+1;j<=n;j++){
			g=g+(j-i)*(a[j]-a[j-1]);
			if(g>m){
				sum=max(sum,j-i);
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
