#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a[10];
ll ans[10],anse=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for (int i=1;i<=4;i++)
    {
        cin>>a[i];
        ans[i]=0;
    }
    if (a[1][0]==a[3][0]&&a[1][1]==a[3][1])
        ans[1]=1;
    if (a[2][0]==a[4][0]&&a[2][1]==a[4][1])
    {
        ans[2]=1;
        if (a[2][2]<='C'&&a[4][2]<='C')
            {
                ans[3]=1;
                if (a[2][2]>a[4][2])
                 {
                    if (a[2][2]-a[4][2]==1)
                     ans[4]=1;
                }
                else
                    if (a[4][2]-a[2][4]==1)
                        ans[4]=1;
            }
        if (a[2][2]>='D'&&a[4][2]>='D')
            {
                ans[3]=1;
                ans[4]=1;
        }
    }
    for (int i=1;i<=4;i++)
        anse=anse*10+ans[i];
    cout<<anse<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}