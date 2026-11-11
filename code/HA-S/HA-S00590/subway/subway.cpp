#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	
	if(n>m)
	{
		a=n-m;
		cout<<29+a<<endl<<14+a;
	}
	
	else if(m>n)
	{
		b=m-n;
		cout<<29+b<<endl<<14+b;
	}
	
	else if(m=n)
	{
		cout<<29<<endl<<14;
	}
	
	return 0;
}
