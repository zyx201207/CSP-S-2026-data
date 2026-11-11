#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;long long S=0;
	cin>>n;
	char c[n],C;int l[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d%c%c%c",l+i,&C,c+i,&C);
	}
	int L=0,R=n-1;
	while(L<R)
	{
		if(c[L]==c[R])
		{
			if(l[L]<l[R])
			{
				l[R]-=l[L++];
			}
			else
			{
				l[L]-=l[R--];
			}
		}
		else
		{
			if(l[L]<l[R])
			{
				S+=l[L];
				l[R]-=l[L++];
				
			}
			else
			{
				S+=l[R];
				l[L]-=l[R--];
			}
		}
	}
	cout<<S;
	return 0;
}
