#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long n,d;
	cin>>n>>d;
	
	if(n>d)
	{
		a=n-d;
		cout<<a<<endl<<a+1;
	}
	
	else if(d>n)
	{
		b=d-n;
		cout<<b-1<<endl<<b;
	}
	
	else if(d=n)
	{
		cout<<n<<endl<<d;
	}
	
	return 0;
}
