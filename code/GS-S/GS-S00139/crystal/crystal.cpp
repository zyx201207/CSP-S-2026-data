#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long a[N],b[N],c[N];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	if(n>5000){
		for(int i=1;i<=n;i++){
			a[i]+=a[i-1];
		}
		int i;
		for(i=1;i<=n;i++){
			if(a[i]>m)break;
		}
		cout<<i;
		return 0; 
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		b[i]=1ll*(a[i]-a[i-1])*(i-1);
		c[i]=b[i]+c[i-1];
	}
	int l=1,r=n;
	while(c[r]-c[l]>m){
		if(b[l]>b[r])l++;
		else r--;
	}
	cout<<r-l+1;
	return 0;
}
