#include<iostream>
using namespace std;
int n,m,b,a,num;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>b;
		for(int j=1;j<=m;j++){
			b+=b;
		}
		num+=b;
	}
	
	return 0;
	
}
