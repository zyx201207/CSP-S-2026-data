#include <bits/stdc++.h>
using namespace std;
long long a[200010],s[200010];
char c[200010];
int b[200010];
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,l=0,d,m=0,j=1;
	cin>>n;
    for(i=1;i<=n;i++)
    {
    	cin>>a[i]>>c[i];
    	l+=a[i];
    	s[i]=a[i]+s[i-1];
    }
    for(i=1;i<=l;i++)
    {
    	if(i>s[j]) j++;
    	b[i]=j;
    }
    for(i=1;i<=l/2;i++)
    {
    	if(c[b[i]]!=c[b[l+1-i]])
    	m++;
    }
    cout<<m;
	return 0;
}


