#include<bits/stdc++.h>
using namespace std;
stack<int> card;
int n,m,a[500005],b[300005],c[300005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            b[a[j]]++;
            c[a[j]]++;
            card.push(a[j]);
            if(b[a[j]]>1)
            {
                card.pop();
                while(!card.empty())
                {
                    b[card.top()]--;
                    c[card.top()]--;
                    card.pop();
                    if(card.top()==a[j])
                    {
                        b[card.top()]--;
                        c[card.top()]--;
                        card.pop();
                        break;
                    }
                }
                card.push(a[j]);
            }

        }
        for(int o=1;o<=m;o++)
            b[o]=0;
    }
    for(int i=1;i<=m;i++)
    {
        if(c[i]!=0)
        {
            cout<<c[i]<<" ";
        }
    }
    return 0;
}
