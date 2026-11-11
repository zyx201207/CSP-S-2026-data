#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,cnt=0;
	cin >> n;
	int a[n+1];
	char b[n+1];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		cin >> b[i];
	}
	int l=1,r=n; 
	while(l<n)
	{
	    if(r==l+1)
	    {
	        cout << cnt;
	        return 0;
		}
	    cnt+=max(a[r],a[l])-min(a[r],a[l]);
	    if(a[l]>a[r])
	    {
	    	a[l+1]+=a[l]-a[r]; 
		}
		else
		{
			a[r+1]+=a[r]-a[l];
		}
	    l++;
	    r--;
	} 
	cout << cnt;
	return 0;
}
