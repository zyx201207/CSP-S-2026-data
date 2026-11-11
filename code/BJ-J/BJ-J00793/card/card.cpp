#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m;
array<int,500003>a;
array<int,300003>ans;
deque<int>dq;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        cout<<n;
    }
    else if(m==2)
    {
        int x=a[n-1];
        for(int i=0;i<n;i++)
        {
            if(a[i]==x)
            {
                ans[a[i]]++;
            }
            else
            {
                ans[1]++;
                ans[2]++;
            }
        }
        cout<<ans[1]<<" "<<ans[2];
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            dq.push_back(a[i]);
            for(int j=i+1;j<n;j++)
            {
                int x=dq.size();
                for(int k=0;k<x;k++)
                {
                    if(dq[k]==a[j])
                    {
                        x=k+1;
                        break;
                    }
                }
                while(dq.size()>x)
                {
                    dq.pop_back();
                }
                dq.push_back(a[j]);
            }
            bool b[n+3];
            memset(b,0x00,sizeof(b));
            while(!dq.empty())
            {
                b[dq.front()]=1;
                dq.pop_front();
            }
        //cout<<"*"<<endl;
            for(int i=1;i<=m;i++)
            {
                ans[i]+=b[i];
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}
