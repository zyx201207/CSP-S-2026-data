#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1000000][100000];
int main(){
    freopen("migrate.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;i++)
        {
            cin>>x[i][j];
            int c=d/x[i][2]-x[i][1];
            cout<<c;
        }
    }
    freopen("migrate.out","w",stdout);
    return 0;
}

