#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
int b[200005];
char s[200005];
int ans=0,len=0;
int mid=(len+1)/2;
int midid;
struct node
{
    int num;
    char c;
};
node l[200005],r[200005];
int rh=0,lh=0,rt=0,lt=0;
char v(int x)
{
    int i=1;
    for(;i<=n&&x>0;x-=a[i++]);
    return s[i-1];
}
inline void BAO_LI()
{
    for(int i=1,j=len;i<=mid;--j,++i)
        if(v(i)!=v(j))
            ++ans;
}
void lpush(int x,char c)
{
    lt++;
    l[lt].num=x;
    l[lt].c=c;
}
void rpush(int x,char c)
{
    rt++;
    r[rt].num=x;
    r[rt].c=c;
}
void lpop()
{
    lh++;
}
void rpop()
{
    rh++;
}
signed main()
{
    freopen("string.in","w",stdin);
    freopen("string.out","w",stdout);
   // :(
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>s[i],b[i]=b[i-1]+a[i];
    len=b[n];
    mid=(len+1)/2;
    for(int i=1;i<=n;i++)
        if(b[i]>=mid)
        {
            midid=i;
            break;
        }
        /*
    for(int i=1;i<=midid;i++)
    {
        if(i!=midid)
            lpush(a[i],s[i]);
        else
        {
            if(b[i]==mid)
                lpush(a[i],s[i]);
            else
                lpush(mid-b[i-1],s[i]);
        }
    }
    for(int i=n;i>=midid;i--)
    {
        if(i!=midid)
             rpush(a[i],s[i]);
        else
        {
            if(b[i-1]+1==mid)
                rpush(a[i],s[i]);
            else
            {
                rpush(b[i]-mid+(len%2!=0)?1:0,s[i]);
                rpush(b[i]-mid+(len%2!=0)?1:0,s[i]);
            }
        }
    }
    for(int i=1;i<=mid;i++)
    {
        int q=min(l[lh].num,r[rh].num);
        i+=q;
        if(l[lh].c==r[rh].c)
        {
            l[lh].num-=q;
            r[rh].num-=q;
            if(l[lh].num==0)
                lpop();
            if(r[rh].num==0)
                rpop();
        }
        else
        {
            ans+=q;
            l[lh].num-=q;
            r[rh].num-=q;
            if(l[lh].num==0)lpop();
            if(r[rh].num==0)rpop();
        }
    }
    cout<<(ans==0)?ans:ans+1;
    return 0;
    */
    BAO_LI();
    cout<<ans;
    return 0;
}
