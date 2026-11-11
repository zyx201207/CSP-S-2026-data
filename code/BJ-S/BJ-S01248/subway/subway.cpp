#include<bits/stdc++.h>
using namespace std;
int w[100000],tr[100000];
int t[100000][100000];
int main(){
    int c,n,m,d,q;
    freopen("subway.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int z;
    cin>>z;
    for(int i=1;i<=2*z+1;i++)
    {
        for(int j=1;j<=2*z+1;j++)
        {
            cin>>t[i][j]>>tr[i];
        }
    }
    for(int u=1;u<=z;y++)
    {
        int x,y;
        cin>>x>>y;
        int cnt=w[x]+w[y]+t[x][x];
        for(int i=1;i<=2*z+1;i++)
        {
            if(t[x][j]==y)
            {
                cnt+=t[x][y];
                break;
            }
        }
        cout<<cnt<<endl;
    }
        freopen("subway.out","w",stdout);
    return 0;
}

