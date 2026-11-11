#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> 	n >> m;
	for(long long i=1;i<=n;i++)cin >> a[i];
	sort(a,a+n);
	for(long long i=1;i<n;i++){
		b[i]=a[1+i]-a[i];
		if(i==1)c[i]=b[i];
		else{
			c[i]=c[i-1]+i*b[i];
			if(c[i]>m){
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}
