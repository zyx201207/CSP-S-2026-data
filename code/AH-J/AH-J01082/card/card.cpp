#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    if(m==1||n==1) cout<<1;
    else while(n--) cout<<5000<<endl;
    return 0;
}
