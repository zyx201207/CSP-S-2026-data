#include <bits/stdc++.h>

using namespace std;
#define int long long

struct qu
{
    char a;
    int l;
    int r;
}lvqqq[200010];

int getlen(int l,int r)
{
    if(r<l)
    {
        return 0;
    }
    return r-l+1;
}

int get_j(qu a,qu b)
{
    return getlen(max(a.l,b.l),min(a.r,b.r));
}

int n;
string s;
int L;

int turn(int p)
{
    return L-p-1;
}

bool cmp(qu a,qu b)
{
    return a.l<b.l;
}

void test()
{
    for(int i=0;i<n;i++)
    {
        cout<<lvqqq[i].a<<endl;
        cout<<lvqqq[i].l<<endl;
        cout<<lvqqq[i].r<<endl;
        cout<<i<<endl;
        cout<<endl;
    }
}

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        //cout<<i<<endl;
        int len;
        cin>>len>>lvqqq[i].a;
        if(i)
        {
            if(lvqqq[i].a==lvqqq[i-1].a)
            {
                L+=len;
                lvqqq[i-1].r=L-1;
                i--;
                n--;
                continue;
            }
        }
        lvqqq[i].l=L;
        L+=len;
        lvqqq[i].r=L-1;
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    //test();
    int mid=L/2;
    int midqu=0;
    for(int i=0;i<n;i++)
    {
        if(lvqqq[i].l<=mid&&lvqqq[i].r>=mid)
        {
            midqu=i;
            if(L%2==0)
            {
                if(lvqqq[i].l==mid)
                {
                    lvqqq[i].l=mid;
                }
                else
                {
                    lvqqq[n].r=lvqqq[i].r;
                    lvqqq[i].r=mid-1;
                    lvqqq[n].l=mid;
                    lvqqq[n].a=lvqqq[i].a;
                    midqu++;
                }
            }
            else
            {
                if(lvqqq[i].l==mid)
                {
                    lvqqq[i].l=mid+1;
                }
                else if(lvqqq[i].r==mid)
                {
                    lvqqq[i].r=mid-1;
                }
                else
                {
                    lvqqq[n].r=lvqqq[i].r;
                    lvqqq[i].r=mid-1;
                    lvqqq[n].l=mid+1;
                    lvqqq[n].a=lvqqq[i].a;
                    n+1;
                    midqu++;
                }
            }
            break;
        }
    }
    int ans=0;
    sort(lvqqq,lvqqq+n,cmp);
    int now=0;
    for(int i=n-1;i>=midqu;i--)
    {
        int aaaa=lvqqq[i].l;
        lvqqq[i].l=turn(lvqqq[i].r);
        lvqqq[i].r=turn(aaaa);
        while(1)
        {
            //cout<<now<<" "<<i<<endl;
            //cout<<ans<<endl;
            //cout<<get_j(lvqqq[i],lvqqq[now])<<endl;
            //cout<<endl;

            if(get_j(lvqqq[i],lvqqq[now])==0)
            {
                if(lvqqq[i].l-1!=lvqqq[now].r)
                {
                    now--;
                }
                break;
            }
            else
            {
                ans+=(get_j(lvqqq[i],lvqqq[now])*(lvqqq[i].a==lvqqq[now].a));
                if(now+1==midqu)
                {
                    break;
                }
                now++;
            }
        }
        //cout<<endl;
        //test();
    }
    cout<<(L/2)-ans<<endl;
    //cout<<L<<endl<<n<<endl;
    return 0;
}
