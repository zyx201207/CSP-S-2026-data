#include<bits/stdc++.h>
using namespace std;
deque<int> a;
deque<char> c;
int change(int st,int cnt,bool t,char cr,int& l,int& r)
{
    int res=0;
    while(a[st]>cnt)
    {
        if(c[st]!=cr)
        {
            res+=a[st];
            cnt-=a[st];
        }
        if(t)
        {
            st--;
            a.pop_back();
            c.pop_back();
        }
        else
        {
            st++;
            a.pop_front();
            c.pop_front();
        }
    }
    a[st]-=cnt;
    if(t)
    {
        l++;
        r=st;
        a.pop_front();
        c.pop_front();
    }
    else
    {
        r--;
        l=st;
        a.pop_back();
        c.pop_back();
    }
    return res;
}
int main()
{
    freopen("stirng.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a1;
    char c1;
    cin>>a1>>c1;
    char lst=c1;
    a.push_back(a1);
    c.push_back(c1);
    for(int i=2;i<=n;i++)
    {
        int x;
        char y;
        cin>>x>>y;
        if(y==lst)
        {
            a[a.size()-1]+=x;
        }
        else
        {
            a.push_back(x);
            c.push_back(y);
        }
        lst=y;
    }
    int aize=a.size(),ans=0;
    for(int l=0,r=aize-1;l<=r;)
    {
         if(a[l]<a[r])
         {
             ans+=change(l+1,a[r]-a[l],false,c[r],l,r);
         }
         else if(a[l]>a[r])
         {
             ans+=change(r-1,a[l]-a[l],true,c[l],l,r);
         }
         else
         {
             if(c[l]!=c[r])
             {
                 ans+=a[l];
             }
             l++;
             r--;
             a.pop_back();
             c.pop_back();
             a.pop_front();
             c.pop_front();
         }
    }
    cout<<ans;
    return 0;
}
