#include <iostream>
using namespace std;
int n,a[200005];
long long c;
string b[200005],s; 
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		c+=a[i];
		for (int j=0;j<a[i];j++) s+=b[i];
	}
    long long d=0;
    for (int i=0;i<c;i++)
    {
    	if (i==c) break;
    	if (s[i]!=s[c]) d++; 
	    c--;
    }
    cout<<d;
	return 0;
} 
