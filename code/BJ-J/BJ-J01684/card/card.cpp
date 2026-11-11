#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MAXN=5*1e5+5;
int a[MAXN];
int tab[MAXN];
int on[MAXN];
int ans[MAXN];

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        int tabcnt=1;
        memset(tab,0,sizeof(tab));
        memset(on,0,sizeof(on));
        for(int j=i;j<=n;j++){
            if(on[a[j]]){
                bool flag=0;
                for(int k=1;k<=tabcnt;k++){
                    if(tab[k]==a[j]){
                        flag=1;
                        tabcnt=k;
                    }
                    if(flag){
                        on[tab[k]]=0;
                        tab[k]=0;
                    }
                }
                tab[tabcnt++]=a[j];
                on[a[j]]=1;
            }
            else{
                tab[tabcnt++]=a[j];
                on[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(on[j]){
                ans[j]++;
            }
        }
    }

    return 0;
}
