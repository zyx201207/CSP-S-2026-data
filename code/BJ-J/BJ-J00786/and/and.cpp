#include<bits/stdc++.h>
using namespace std;
int erjinzhi(int n)
{
    int ans=0,x=1;
    while(n>0)
    {
        ans+=n%2*x;
        x*=10;
        n=n/2;
    }
    return ans;
}
int yu(int n,int m)
{
    int ans=0,x=1;
    while(n>0||m>0)
    {
        if(n%10==m%10&&n%10!=0)
        {
            ans+=1*x;
        }
        x*=10;
        m=m/10;
        n=n/10;
    }
    return ans;
}
int shijinzhi(int n)
{
    int x=1,ans=0;
    while(n>0)
    {
        ans+=n%10*x;
        x*=2;
        n/=10;
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[2^30],b[2^30];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=erjinzhi(a[i]);
    }
    if(m==1)
    {
        int x=-1;
        for(int i=1;i<=n;i++)
        {
            m=max(a[i],m);
        }
        cout<<m;
        return 0;
    }
    else
    {
        int m=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                m=max(m,yu(b[i],b[j]));
                //cout<<b[i]<<" "<<b[j]<<" "<<yu(b[i],b[j])<<" "<<m<<endl;
            }
        }
        cout<<shijinzhi(m);
        return 0;
    }
}
