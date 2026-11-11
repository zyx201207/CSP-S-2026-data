#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[500005],b[500005],b1[500005];
stack<int>t;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int k=a[j];
            b[k]++;
            if(b[k]>1)
            {
                b[k]=1;
                while(t.top()!=k)
                {
                    b[t.top()]--;
                    t.pop();
                }
                t.pop();
            }
            else{
                t.push(k);
            }
        }
        for(int i=1;i<=m;i++)
        {
            b1[i]+=b[i];
            b[i]=0;
        }
    }
    for(int i=1;i<=m;i++)cout<<b1[i];
    return 0;
}
