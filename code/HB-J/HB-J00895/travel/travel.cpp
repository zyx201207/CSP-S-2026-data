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

bool isPrime(int n)
{
    if(n==0||n==1)return 0;
    forlr(2,sqrt(n))
    {
        if(n%i==0)return 0;
    }
    return 1;
}


int c1,c2;
string s1,s2;
int a1,a2;
char b1,b2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>a1>>b1>>c2>>a2>>b2;
    if(c1==c2)
    {
        cout<<1;
        if(a1==a2)
        {
            cout<<1;
            if((b1<'D')==(b2<'D'))
            {
                cout<<1;
                if(b1=='A'&&b2=='C'||b1=='C'&&b2=='A')cout<<0;
                else cout<<1;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
}
