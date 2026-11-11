#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define fori(n) for(int i=1;i<=n;i++)
#define forj(n,j) for(int j=1;j<=n;j++)
#define forlr(l,r) for(int i=l;i<=r;i++)
#define forlrj(l,r,j) for(int j=l;j<=r;j++)
#define ford(i) for(int i=n;i>=1;i--)
#define fordj(n,j) for(int j=n;j>=1;j--)
#define forlrd(r,l) for(int i=r;i>=l;i--)
#define forlrdj(r,l,j) for(int j=r;j>=l;j--)
//Track||Treat!

bool isPrime(int n)
{
    if(n==0||n==1)return 0;
    forlr(2,sqrt(n))
    {
        if(n%i==0)return 0;
    }
    return 1;
}


int n,m,a;
string s[200005];
bool tag[200005];


/** n*logn */
int main()
{
    /*
    int n,m,a;
    string s[200005];
    bool tag[200005];
    */

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    fori(n)
    {
        scanf("%d",&a);
        string t=" ";
        int b=1073741824;
        forj(31,j)
        {
            if(a>=b)
            {
                a-=b;
                t=t+'1';
            }
            else t=t+'0';
            s[i]=t;
            b/=2;
        }
    }

    /*
    fori(n)
    {
        cout<<s[i]<<'\n';
    }
    cout<<"\n";
    */

    int ans=0,b=1073741824;
    fori(31)
    {
        int cnt=0;
        forj(n,j)
        {
            if(tag[j])continue;
            if(s[j][i]=='1')cnt++;
        }
        if(cnt>=m)
        {
            forj(n,j)
            {
                if(s[j][i]=='0')tag[j]=1;
            }
            ans+=b;
        }
        //cout<<cnt;
        b/=2;
    }
    //cout<<"\n";

    cout<<ans;
}
