#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n[2000],d[2000];
long long N[200][200];
int main()
{
    freopen("migrate.in","w",stdin);
    freopen("migrate.out","r",stdout);
    cin>>c,t;
    for(int i=0;i<t;i++)
    {
        cin>>n[i]>>d[i];
        for(int j=0;j<n[i];j++)
        {
            cin>>N[i][j];
        }
    }
    return 0;
}
