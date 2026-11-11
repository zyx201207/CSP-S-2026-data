#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int cnt[N],ans[N],st[N],top;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        top=0;
        for(int j=i;j<=n;j++){
            if(cnt[a[j]]==1){
                while(top){
                    cnt[a[st[top]]]--;
                    if(a[st[top]]==a[j]){
                        top--;
                        break;
                    }
                    top--;
                }
            }
            cnt[a[j]]++;
            st[++top]=j;

        }
        for(int j=1;j<=m;j++){
            if(cnt[j]) ans[j]++;
            cnt[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}

