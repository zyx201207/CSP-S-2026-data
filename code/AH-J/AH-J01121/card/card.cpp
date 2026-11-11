#include<bits/stdc++.h>

using namespace std;

int n,m;
int s[500011];
int z[300011];
int a[300011];
int ans[300011];

int main () {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) {
        scanf("%d",&s[i]);
    }
    memset(ans,0,sizeof(ans));
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        memset(z,0,sizeof(z));
        memset(a,0,sizeof(a));
        for(int j = i; j <= n; j++){
            if(z[s[j]] > 0){
                bool b = false;
                for(int k = 1; k <= cnt; k++){
                    if(a[k] == s[j]){
                        b = true;
                        cnt--;
                        z[s[j]]--;
                    }else if(b && z[a[k]] > 0){
                        cnt--;
                        z[a[k]]--;
                    }
                }
            }
            a[++cnt] = s[j];
            z[s[j]]++;
        }
        for(int j = 1; j <= m; j++)
            if(z[a[j]] > 0)
                ans[j]++;
    }
    for(int i = 1; i <= m; i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
