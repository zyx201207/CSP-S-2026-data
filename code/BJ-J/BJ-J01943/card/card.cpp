#include<bits/stdc++.h>
using namespace std;
int vhs[500005],tir[500005],ub[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int noau[500005];
    stack<int> a;
    stack<int> b;
    int n,m,mx=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>noau[i];
    for(int st=0;st<n;st++)
    {
        fill(vhs,vhs+mx,0);
        fill(tir,tir+mx,0);
        for(int i=st;i<n;i++)
        {
            mx=max(mx,noau[i]);
            a.push(noau[i]);
            tir[noau[i]]++;
            if(vhs[noau[i]]==1)
            {
                while(a.top()!=noau[i])
                {
                    tir[a.top()]--;
                    if(tir[a.top()]==0)
                        vhs[a.top()]=0;
                    a.pop();
                }
            }
            vhs[noau[i]]=1;
        }
        for(int i=1;i<=mx;i++)
        {
            ub[i]+=vhs[i];
            cout<<vhs[i];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ub[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
