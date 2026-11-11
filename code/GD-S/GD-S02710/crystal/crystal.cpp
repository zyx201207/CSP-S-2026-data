#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long cry[maxn],b[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //用long long
    long long curr,m;int n;
    scanf("%d %lld",&n,&m);

    for(int i=1;i<=n;i++){
        scanf("%lld",&cry[i]);
    }
    sort(cry+1,cry+n+1);
    for(int i=1;i<=n;i++)b[i]=b[i-1]+cry[i];
    int j=1,best=1;
    for(int i=1;i<=n;i++){
        while((i-j+1)*cry[i]-(b[i]-b[j-1])>m)j++;
        best=max(best,i-j+1);
    }
    printf("%d",best);
    fclose(stdin);fclose(stdout);
}