#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;
ll a[MAXN];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ll n1,m1,n2,m2;
    char s1,s2;
    scanf("%lld%lld",&n1,&m1);
    cin>>s1;
    scanf("%lld%lld",&n2,&m2);
    cin>>s2;
    if(n1==n2)
    {
        printf("1");
    }
    else
    {
        printf("0000");
        return 0;
    }
    if(m1==m2)
    {
        printf("1");
    }
    else
    {
        printf("000");
        return 0;
    }
    if((s1>='A'&&s1<='C'&&s2>='A'&&s2<='C')||((s1=='D'||s1=='F')&&(s2=='D'||s2=='F')))
    {
        printf("1");
    }
    else
    {
        printf("00");
        return 0;
    }
    if(s1==s2-1||s1-1==s2||((s1=='D'&&s2=='F')||(s1=='F'&&s2=='D')))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
}
