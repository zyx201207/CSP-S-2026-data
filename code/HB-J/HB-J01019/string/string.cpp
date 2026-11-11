#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int l;
    int r;
    char p;
}s[300100],s1[300100];
bool cmp(struct node x,struct node y)
{
    return x.l>y.l;
}

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,head=0;
    cin>>n;
    int l;
    if (n<=3000)
    {
         char s2[5000100];
    for(int i=0;i<n;i++)
    {
        int k;
        char m;
        cin>>k>>m;
        for (int j=head;j<head+k;j++)
        {
            s2[j]=m;
        }
        head+=k;
    }
    //cout<<head;
    int ans=0;
    for (int i=0;i<head/2;i++)
    {
        if(s2[i]!=s2[head-i-1])
            ans++;
    }
    cout<<ans;
    return 0;
    }
    for(int i=0;i<n;i++)
    {
       // cout<<"input"<<endl;
        s[i].l=head;
        //scanf("%lld %lld",l,s[i].p);
        cin>>l>>s[i].p;
        head+=l;
        s[i].r=head;
    }
    //dont care about head%2!=0 for now qwq
    int mid=head/2;
    if (head%2)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i].r>mid)
                s[i].r--;
            if(s[i].l>mid)
                s[i].l--;
        }
    }
    head--;
    //int newn=n;
    int x=-1;
    //cout<<"miao1";
    for(int i=0;i<n;i++)
    {
        if (s[i].l==mid)
        {
            x=i;
            break;
        }
        //ate a candy, yum
        if (s[i].l<mid&&s[i].r>mid)
        {
            int rn=s[i].r,pn=s[i].p;
            x=i;
            s[i].r=mid;
            s[n].l=mid;
            s[n].r=rn;
            s[n].p=pn;
            n++;
            break;
        }
    }
    //cout<<mid<<" "<<x<<endl;
    for(int i=x;i<n;i++)
    {
        if (s[i].l<mid)
            continue;
        //fold the right half of the string
        int rn=s[i].l,ln=s[i].r,pn=s[i].p;
        rn=head-rn;
        ln=head-ln;
        s1[i-x].l=ln;
        s1[i-x].r=rn;
        s1[i-x].p=pn;
    }
     //cout<<"miao2";
    sort(s1,s1+n-x,cmp);
    //sort(s,s+n,cmp);
    //cout<<s1[0].l<<" "<<s1[0].r<<" "<<s1[0].p<<endl;
    int xx=0,yy=0,ans=0;
    int nl=0;
        int nr=min(s[xx].r,s1[yy].r);
    int sx,sy;
    ans=0;
    for (sx=0;s[sx].r!=mid;sx++);
    for (sy=0;s1[sy].r!=mid;sy++);
    while(xx<=sx&&yy<=sy)
    {
        //cout<<"WORK"<<endl;
        //double-pointer perhaps?
        nr=min(s[xx].r,s1[yy].r);
   // cout<<nr-nl<<endl;
        if (s[xx].p!=s1[yy].p)
        {
            //cout<<"111";
            ans+=nr;
            ans-=nl;
        }
            nl=nr;
        if (nr==s[xx].r)
        {
            xx++;
        }
        if (nr==s1[yy].r)
        {
            yy++;
        }

    }
    cout<<ans;
    return 0;
}
