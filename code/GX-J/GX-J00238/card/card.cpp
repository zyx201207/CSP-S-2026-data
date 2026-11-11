#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
bool v[300005];
stack<long long> st;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(long long j=1;j<=n;j++)
    {
        fill(v+1,v+m+1,0);
        while(!st.empty()) st.pop();
        for(long long i=j;i<=n;i++)
        {
            if(!v[a[i]])
            {
                v[a[i]]=1;
                sum[a[i]]++;
                st.push(a[i]);
            }
            else
            {
                while(st.top()!=a[i])
                {
                    v[st.top()]=0;
                    sum[st.top()]--;
                    st.pop();
                }
            }
        }
    }
    for(long long i=1;i<=m;i++)
        printf("%lld ",sum[i]);
    return 0;
}
