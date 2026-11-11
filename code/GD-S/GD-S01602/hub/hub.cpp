#include<bits/stdc++.h>

using namespace std;


int c,t;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for (int i=0;i<t;i++)
	{
		int n,k,xynk[1000005][1000005];
		for (int j=0;j<n;j++)
		{
			int un,yn;
			cin>>un>>yn;
			xynk[un][yn]=j;
		}
		
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
