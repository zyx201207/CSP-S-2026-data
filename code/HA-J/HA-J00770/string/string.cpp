#include <bits/stdc++.h>
using namespace std;
int n,ai[200005],f,r;
long long c;
char ci[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>ai[i]>>ci[i];
	r=n-1;
	while(f<r)
	{
		if(ci[f]==ci[r])
		{
			if(ai[f]>ai[r])
			{
				ai[f]-=ai[r];
				r--;
			}	
			else if(ai[f]<ai[r])
			{
				ai[r]-=ai[f];
				f++;
			}
			else
			{
				f++;
				r--;
			}
		}
		else
		{
			if(ai[f]>ai[r])
			{
				ai[f]=ai[f]-ai[r];
				c+=ai[r];
				r--;
			}		
			else if(ai[f]<ai[r])
			{
				ai[r]=ai[r]-ai[f];
				c+=ai[f];
				f++;
			}
			else if(ai[f]==ai[r])
			{
				c+=ai[f];
				f++;
				r--;
			}
		}
	}
	cout<<c;
	return 0;
}
