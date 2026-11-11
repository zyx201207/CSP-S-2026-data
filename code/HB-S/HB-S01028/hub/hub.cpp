#include <bits/stdc++.h>
using namespace std;
int rd(){
    int sum=0;int min=1;char c='a';
    while(c<'0'||c>'9')
    {
        if(c=='-') min=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9')
    {
        sum=(sum<<3)+(sum<<1)+c-'0';
        c=getchar_unlocked();
    }
    return sum*min;
}
//int const INF=1e6+1;
//int prime[INF];bool not_prime[INF];
/*void f(int n)
{
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(!not_prime[i])
            prime[++cnt]=i;
        for(int j=1;j<=cnt&&j<=n;j++)
        {
            not_prime[i*prime[j]]=true;
            if(i%j==0) break;
        }
    }
}
int fast_pow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}*/