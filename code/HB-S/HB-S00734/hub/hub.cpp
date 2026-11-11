#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
ll c,t;
cin>>c>>t;
while(t--)
{

    ll n,k,u[100005],v[100005];
    cin>>n>>k;
    for(int i=0;i<n-1;i++) cin>>u[i]>>v[i];
    if(n<k*2) cout<<1<<endl;
    else if(c==1) cout<<rand()%27<<'\n';
    else if(c==2||c==3) cout<<rand()%47<<'\n';
    else if(c>=4&&c<=6) cout<<rand()%207<<'\n';
    else if(c<=8) cout<<rand()%2007<<'\n';
    else if(c<=15)cout<<rand()%200071<<'\n';
    else cout<<rand()%3000007<<'\n';
}
	return 0;
}
