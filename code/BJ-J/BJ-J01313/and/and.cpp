#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,chuan[200005];
bool vis[200005],num[200005][35];
string str[200005],ansstr;
bool cmp(string x,string y)
{
    return x>y;
}
void fenjie(int nu,int s)
{
    for(int i=0;i<=30;i++)
    {
        string t;
        t='0'+nu%2;
        nu/=2;
        str[s]=t+str[s];
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fenjie(a[i],i);
    }
    sort(str+1,str+n+1,cmp);
    for(int i=30;i>=0;i--)
    {
        bool flag=1;
        for(int j=1;j<=m;j++)
        {
            if(str[j][i]=='0')
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            ansstr=ansstr+"1";
        }
        else
        {
            ansstr=ansstr+"0";
        }
    }
    for(int i=0;i<=30;i++)
    {
        if(ansstr[i]=='1')
        {
            ans+=pow(2,i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
