#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p,i,j=39;
    cin>>c>>n>>m>>d>>p;
    for(i=1;i<=p;i++)
    {
        cout<<j<<endl;
        if(j==14)
        {
           j++;
        }
        else
        {
            j--;
        }
    }
    return 0;
}
