//GZ-J00083 南明区山水中学 张皓宇
#include<bits/stdc++.h>
using namespace std;
bool sun[1000000],bl=0;
int a[1000000],b[1000000],c[1000000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
        }
    }
    for(int i=1;i<=n;i++){
        int s=0;
        int x=a[i];
        while(x>0){
            int z=x%2;
            x/=2;
            s+=z;
        }
        b[i]=s;
    }
    int maxn=-190,bl;
    for(int i=1;i<=m;i++){
        maxn=-190;
        for(int j=1;j<=n;j++){
            if(maxn<b[j]){
                maxn=max(maxn,b[j]);
                bl=j;
            }
        }
        c[++cnt]=bl;
        b[bl]=0;
    }
    int ans=a[c[1]];
    for(int i=2;i<=m;i++){
        ans=(ans&a[c[i]]);
    }
    cout<<ans;
    return 0;

}
