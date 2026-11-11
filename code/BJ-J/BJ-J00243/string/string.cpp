#include<bits/stdc++.h>
using namespace std;
const int M=1e5*2+20;
struct node
{
    long long num;
    char ch;
}b[M];
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,ans=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long a;
        char c;
        cin>>a>>c;
        b[i].num=a;
        b[i].ch=c;
    }
    long long fin=n,nu=0;
    for(long long i=1;i<=n;i++)
    {
        if(fin==i)
        {
            break;
        }
        if(nu==b[fin].num)
        {
            fin--;
            nu=0;
        }
        long long y=b[i].num;
        while(1)
        {
            long long x=b[fin].num-nu;
            if(x==y)
            {
                if(b[fin].ch!=b[i].ch)
                {
                    ans+=y;
                }
                nu=0;
                fin--;
                break;
            }
            else if(x>y)
            {
                nu+=y;
                if(b[fin].ch!=b[i].ch)
                {
                    ans+=y;
                }
                break;
            }
            else if(y>x)
            {
                nu=0;
                y-=x;
                if(b[fin].ch!=b[i].ch)
                {
                    ans+=x;
                }
                fin--;
            }
        }
        if(fin==i)
        {
            break;
        }

    }
    cout<<ans;
    return 0;
}

