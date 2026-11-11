#include<bits/stdc++.h>
using namespace std;
char a[101];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b=0;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
		if(i%2==1)
		{
			if(a[0]==a[i]||a[1]==a[i-1]||a[2]==a[i-2])
			{
				b=b+0;
			}
			else
			{
				if(a[0]!=a[i])
				{
					b=b+1;
				}
				if(a[1]!=a[i-1])
				{
					b=b+1;
				}
				if(a[2]!=a[i-2])
				{
					b=b+1;
				}
			}
		}
		else
		{
			if(a[0]==a[i])
			{
				b=b+1;
			}
			if(a[1]==a[i-1])
			{
				b=b+1;
			}
			if(a[2]==a[i-2])
			{
				b=b+1;
			}
		}
		
	}
	cout<<b;
	return 0;
}
