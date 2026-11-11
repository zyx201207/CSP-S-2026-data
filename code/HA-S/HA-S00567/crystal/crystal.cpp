#include<bits/stdc++.h>
using namespace std;
long long n,m,f;
long long a[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) b[i]=b[i-1]+((a[i]-a[i-1])*(i-1));
	long long x=n,y=n;
	while(y>0){
		long long t=0;
		while(1){
			t=b[y]-b[x]-((a[y]-a[x])*(x-1));
			if(x<=0||t>m){
				break;
			}
			x--;
		}
		f=max(f,(y-x));
		y--;
	}
	cout<<f;
	return 0;
}
