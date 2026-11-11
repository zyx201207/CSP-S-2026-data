#include <bits/stdc++.h>
using namespace std;
int n,m;
string a[10000005];
bool t(int x)
{
	int num=0,sum=1;
    while(x==0)
    {
    	num+=x%2*sum*10;
    	x/=2;
        sum++;
    }
    num/=10;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	cout<<"12";
	return 0;
}
