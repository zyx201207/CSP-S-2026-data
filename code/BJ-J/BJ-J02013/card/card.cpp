#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,a[N],m,js,sz[M],mn[M],ans[M];
signed main(){
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        js=1;
        for (int j=i;j<=n;j++){
            if (sz[a[j]]==0){
                sz[a[j]]++;
                mn[js]=a[j];
                js++;
                /*for (int j=1;j<=m;j++){
            cout << sz[j] << " ";
        }
        cout << endl;*/
            }
            else{
                for (int k=1;k<js;k++){
                    if (a[j]==mn[k]){
                        for (int l=js-1;l>k;l--){
                            sz[mn[l]]--;
                        }
                        js=k+1;
                        /*for (int j=1;j<=m;j++){
            cout << sz[j] << " ";
        }
        cout << js;
        cout << endl;*/
                        break;
                    }
                }
            }
        }
        for (int j=1;j<=js-1;j++){
            ans[mn[j]]++;
        }

        memset(sz,0,sizeof(sz));
    }
    for (int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
        