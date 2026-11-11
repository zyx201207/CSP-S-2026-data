#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n, d;
long long a[1000005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	for(int i = 1;i<=t;i++)
	{
		cin>>n>>d;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i];
		}
		int cha  = a[2] - a[1];
		if(d < cha*2) 
		{
			cout<<"0";
			return 0;
		}
		else if(d >= cha*2 && d < cha*3) 
		{
			cout<<(n-2);
			return 0;
		}
		else if(d >= cha*3 )
		{
			cout<<'2';
			return 0;
		}
		cout<<endl;
	}
	return 0;
}
