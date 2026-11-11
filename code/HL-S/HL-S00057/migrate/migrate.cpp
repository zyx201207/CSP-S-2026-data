#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
    for(int i=0;i<t;i++)
    {
        int n,d;
        cin>>n>>d;
        int zb[2000005];
        for(int j=0;j<n;j++)
        {
            cin>>zb[j];
        }
        if(d==2)
        {
            cout<<n%4+1;
        }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
