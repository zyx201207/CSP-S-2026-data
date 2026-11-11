#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
const int M=2e5+10;
stack<int> s;
int a[N];
int na[N];
bool has[M];
int num[M];
int rep[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    bool part=1;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i-1]>a[i])part=0;
    }
    if(part==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=a[i+1])cout<<i<<" ";
        }
        return 0;
    }
    if(m<=2)
    {
        int o=0,t=0;
        if(a[n]==1)
        {
            o=n;
            for(int i=1;i<=n;i++)if(a[i]==2)t++;
        }
        else
        {
            t=n;
            for(int i=1;i<=n;i++)if(a[i]==1)o++;
        }
        if(m==2)cout<<o<<" "<<t;
        else cout<<o;
        return 0;
    }
    //memset(has,0,sizeof(has));
    for(int i=1;i<=n;i++)
    {
        memset(has,0,sizeof(has));
        for(int j=i;j<=n;j++)
        {
            if(has[a[j]])
            {
                while(s.top()!=a[j])
                {
                    has[s.top()]=0;
                    s.pop();
                }
            }
            else
            {
                s.push(a[j]);
                has[a[j]]=1;
            }
        }
        while(!s.empty())
        {
            //cout<<s.top()<<endl;
            num[s.top()]++;
            //cout<<num[s.top()]<<"top"<<endl;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<num[i]<<" ";
    return 0;
}
