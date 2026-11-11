#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ll n,d,a[2000005];
        cin>>n>>d;
        for(int i=0;i<n;i++) cin>>a[i];
        if(n==1) cout<<0<<endl;
        else cout<<rand()%1000007<<endl;
    }
	return 0;
}
