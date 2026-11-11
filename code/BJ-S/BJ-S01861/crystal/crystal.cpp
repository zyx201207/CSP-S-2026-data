#include<bits/stdc++.h>
using namespace std;
long long n,m,p[500005],q[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    sort(p,p+n);
    for(int i=n;i>=0;i--)
        for(int j=i-1;j>=0;j--)
            q[i]+=p[i]-p[j];
    for(int i=n-1;i>=0;i--)
        if(q[i]<=m){
            printf("%d",i+1);
            return 0;
        }
    return 0;
}
