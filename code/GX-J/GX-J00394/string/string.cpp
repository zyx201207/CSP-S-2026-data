#include<bits/stdc++.h>
using namespace std;
int n,k=1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    char in[n+1][3];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2;j++)
        {
            cin>>in[i][j];
        }
    }
    if(n==1) cout<<"0";
    if(n==2&&in[1][2]==in[2][2]) cout<<"0";
    if(n==2&&in[1][2]!=in[2][2]) cout<<min(in[1][1],in[2][1]);
    return 0;
}
