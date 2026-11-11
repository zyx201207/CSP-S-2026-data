#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],c[N];
long long sum1[N],sum2[N],ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    if(n==1||n==2){
        cout<<0<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++){
        long long aa;
        char cc;
        cin>>aa>>cc;
        a[i]=aa;
        c[i]=cc;
    }
    for(int i=1;i<=n;i++)
        sum1[i]=sum1[i-1]+a[i];
    /*sum1[1]=a[1];
    sum1[2]=sum1[2-1]+a[2];
    sum1[3]=sum1[3-1]+a[3];*/
    for(int i=n;i>=1;i--)
        sum2[i]=sum2[i+1]+a[i];
    long long i=1,tot1=1,j=sum1[n],tot2=n;
    while(i<j){
        if(i>sum1[tot1])tot1++;
        if(j<sum2[tot2])tot2--;
        if(c[tot1]!=c[tot2])ans++;
        i++,j--;
    }
    cout<<ans<<'\n';
    return 0;
}