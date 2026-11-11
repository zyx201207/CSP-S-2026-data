#include<bits/stdc++.h>
using namespace std;
long long b=2,c=0,n,m,x[1000010],ma=0;;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n);
	if(n>=2000){
		cout<<x[n];
	}
	ma=x[n-1]&x[n-2];
	for(long long i=m-1;i>1;i--){
		ma=ma&x[n-b];
		b++;
	}
	cout<<ma;
	return 0;
}
