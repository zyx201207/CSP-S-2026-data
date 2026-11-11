#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans,st[200005][20],box[5];
void init()
{
    for (int i=1;i<=n;++i)
    {
        st[i][0]=a[i];
    }
    for (int j=1;(1<<j)<=n;++j)
    {
        for (int i=1;i<=n;++i)
        {
            st[i][j]=st[i][j-1]&st[min(i+(1<<(j-1)),n)][j-1];
        }
    }
}
long long raq(int l,int r)
{
    if (l>r)return 0x7fffffff;
    long long len=r-l+1;
    long long lglen=__lg(len);
    long long t=1<<lglen;
    return st[l][lglen]&st[r-t+1][lglen];
}
void dfs(int step,long long sum,int ch)
{
    //cout<<"step="<<step<<" sum="<<sum<<" ch="<<ch<<endl;
    if (n-step+1<m-ch)return;
    if (step==n+1)
    {
        ans=max(ans,sum);
        return;
    }
    dfs(step+1,sum,ch);
    if (ch<m)
    {
        //cout<<"a["<<step<<"]="<<a[step];
        //cout<<" sum&a[step]="<<(sum&a[step])<<endl;
        dfs(step+1,sum&a[step],ch+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    bool flaga=true;
    bool flagb=((1<<__lg(n))==n);
    bool flagc=true;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if ((1<<__lg(a[i]+1))!=a[i]+1)
        {
            flaga=false;
        }
        if (a[i]!=i-1)
        {
            flagb=false;
        }
        if (a[i]>=4)
        {
            flagc=false;
        }
    }
    if (n<=20)
    {
        dfs(1,0x7fffffff,0);
        cout<<ans<<endl;
        return 0;
    }
    if (m==1)
    {
        for (int i=1;i<=n;++i)
        {
            ans=max(ans,a[i]);
        }
        cout<<ans<<endl;
        return 0;
    }
    if (m==n)
    {
        ans=0x7fffffff;
        for (int i=1;i<=n;++i)
        {
            ans&=a[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    if (m==2)
    {
        for (int i=1;i<=n;++i)
        {
            for (int j=i+1;j<=n;++j)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    if (m==n-1)
    {
        init();
        for (int i=1;i<=n;++i)
        {
            ans=max(ans,raq(1,i-1)&raq(i+1,n));
        }
        cout<<ans<<endl;
        return 0;
    }
    if (flaga)
    {
        sort(a+1,a+n+1);
        cout<<a[n-m+1]<<endl;
        return 0;
    }
    if (flagb)
    {
        ans=n-1;
        for (int i=n-1;i>=n-m+1;--i)
        {
            ans&=a[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    if (flagc)
    {
        for (int i=1;i<=n;++i)
        {
            ++box[a[i]];
        }
        if (box[3]>=m)
        {
            cout<<3<<endl;
            return 0;
        }
        if (box[2]+box[3]>=m)
        {
            cout<<2<<endl;
            return 0;
        }
        if (box[3]+box[1]>=m)
        {
            cout<<1<<endl;
            return 0;
        }
        cout<<0<<endl;
        return 0;
    }
    return 0;
}