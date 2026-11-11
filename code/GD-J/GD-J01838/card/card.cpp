#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],ans[300005],d[500005],b[500005],s[500005];
int f[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >>n >>m;
    for(int i = 1;i <= n;i++){
        cin >>a[i];
    }
    if(m == 2){
        for(int i = 1;i <= n;i++){
            if(a[i] == a[n])ans[a[n]]++;
            else{
                ans[a[n]]++;
                ans[a[i]]++;
            }
        }
        cout << ans[1] << " " << ans[2];
    }
    for(int i = 1;i <= n;i++){
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        int cnt = 0;
        for(int j = 1;j <= n;j++)d[j] = a[j] - a[j-1];
        for(int j = i;j <= n;j++){
            b[++cnt] = a[j];
            if(f[b[j]]){
                for(int k = f[b[cnt]];k < cnt;k++)b[k] = 0;
            }
            f[b[cnt]] = cnt;
        }
        for(int j = i;j <= n;j++){
            cout <<b[j] <<endl;
            if(b[j] > 0)ans[b[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout <<ans[i] <<" ";
    }
}
