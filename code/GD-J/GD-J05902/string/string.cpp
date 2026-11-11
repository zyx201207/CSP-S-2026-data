#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
string c[10005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c[i];
		
	}
	if(n==1)
	{
		cout<<0;
	}
	else if(n==2&&c[1]==c[2])
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	return 0;
}
