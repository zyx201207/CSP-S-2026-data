#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


int cnt[210000];
char c[210000];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d %c",&cnt[i],&c[i]);
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r) {
        // printf("%d %d  %d %d\n",l,r,cnt[l],cnt[r]);
        int x=min(cnt[r],cnt[l]);
        if(c[l]!=c[r]) ans+=x;
        cnt[r]-=x,cnt[l]-=x;
        if(cnt[r]==0) r--;
        if(cnt[l]==0) l++;
    }
    printf("%lld\n",ans);
}