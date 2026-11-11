#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long z[500010];
long long b,c,d,e,sum;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		z[i] = a[i]-a[i-1];
	}
	for(int i = 1;i<=n;i++){
		c = d*z[i]+c;
		d++;
		while(c>m&&e<=i){
			c = c-(a[i]-a[e]);
			e++;
			d--;	
		}
		sum = max(sum,d);
	}
	cout<<sum;
	return 0;
}
