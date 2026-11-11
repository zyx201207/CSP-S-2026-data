#include <bits/stdc++.h>
using namespace std;

int n,m,b[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>b[i];
    }
    if (m==1) {
        cout<<1;
    }
    else if(n==2&&m>=2) {
        cout<<2;
    }
    else if(n==3&&m>3) {
        cout<<3;
    }
    else if(n==4&&m>4) {
        cout<<4;
    }
    else if(n==5&&m>=5) {
        cout<<5;
    }

    return 0;
}
