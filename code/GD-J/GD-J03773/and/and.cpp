#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int a[210000];
int vis[210000];

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=30;i>=0;i--) {
        int cnt=0;
        for(int j=1;j<=n;j++) {
            if(vis[j]) continue;
            if((a[j]>>i)&1) cnt++;
        }
        if(cnt>=m) {
            ans|=(1<<i);
            for(int j=1;j<=n;j++) {
                if(!((a[j]>>i)&1)) vis[j]=1;
            }
        }
    }
    printf("%d\n",ans);
}