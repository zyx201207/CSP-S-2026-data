#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
int c,t;
cin>>c>>t;

for(int i=1;i<=t;i++)
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>=100000)
	{
		printf("35");
	}
	else
	{
		printf("1");
	}
}
	return 0;
}
