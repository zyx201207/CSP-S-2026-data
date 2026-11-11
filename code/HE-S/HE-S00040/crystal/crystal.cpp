#include<bits/stdc++.h>
using namespace std;
long long n,m,l,maxx=-1;
long long a[500005];
long long sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		while((i-l)*a[i]-(sum[i]-sum[l])>m){
			l++;
		}
		maxx=max(maxx,i-l);
	}
	cout<<maxx;
	return 0;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7

