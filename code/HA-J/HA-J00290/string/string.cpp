#incdule<bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005];
int main()
{
	//freopen("string.in","r",stdin)
	//freopen("string.out","w",stdout)
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i]>>b[i];
	if(n==1)
	    cout<<0;
	if(n==2)
	{
		if(b[0]==b[1])
		    cout<<0;
		else
		{
			if(a[0] > a[1])
			    cout<<a[1];
			else
			    cout<<a[0];
		}
	}
	return 0; 
}
