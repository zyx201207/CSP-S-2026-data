#include <bits/stdc++.h>
using namespace std;
int a[210000],n,m;
int v[100000];
int ans[100000];
stack<int>s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(v[a[j]]==0)
            {
                v[a[j]]=1;
                s.push(a[j]);
            }
            else
            {
                while(s.top()!=a[j])
                {
                    v[s.top()]=0;
                    s.pop();
                }
            }
        }
        while(!s.empty())
        {
            //cout<<s.top()<<" ";
            ans[s.top()]++;
            s.pop();
        }
        for(int i=0;i<100000;i++)
        {
        v[i]=0;
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
