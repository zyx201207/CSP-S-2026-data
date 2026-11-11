#include<bits/stdc++.h>
using namespace std;
#define itn int
#define ll long long
int c,T;
int n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(itn i=1;i<=n;i++)
            cin>>x[i];
        if(d<x[i])
        {
            cout<<"0\n";
            return 0;
        }
        cout<<n-3<<"\n";
    }
    
	return 0;
}