#include <bits/stdc++.h>
using namespace std;
int a[1000000];
char b[1000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,maxn=-1,cnt=0;
	cin>>n;
	if(n==1)
	{
	    cout<<"0"; 
	    return 0;
	}
	if(n==2)
	{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		maxn=max(maxn,a[i]);
		cnt+=a[i];
    }
	cout<<cnt-maxn;
    }
}
