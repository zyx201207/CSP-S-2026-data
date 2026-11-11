#include<bits/stdc++.h>
const long long N=2e5+5;
long long a[N],na[N],n,nd,ans;
char b[N],nb[N];
int main()
{
    std::freopen("string.in","r",stdin);
    std::freopen("string.out","w",stdout);
    nb[0]='$';
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    std::cin >> n;
    for(int i=1;i<=n;++i)
    {
        std::cin >> a[i] >> b[i];
        if(b[i]==nb[nd])
            na[nd]+=a[i];
        else
            na[++nd]=a[i],nb[nd]=b[i];
    }
    for(int i=1,j=nd;i<=nd&&j>=1;)
    {
        long long t=std::min(na[i],na[j]);
        if(nb[i]!=nb[j])
            ans+=t;
        na[i]-=t;
        na[j]-=t;
        if(!na[i])i++;
        if(!na[j])j--;
        if(i==j)break;
    }
    std::cout << ans;
    return 0;
}
