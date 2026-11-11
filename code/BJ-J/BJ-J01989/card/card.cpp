#include<bits/stdc++.h>

using namespace std;
int n,m;
int ans[30000];
int card[50000];
int a[50000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> card[i];
    }
        for(int i = 1;i<=n;i++){
            int top = 0;
            for(int j = i;j<=n;j++){
                int sign =0;
                for(int p = top;p>=1;p--){
                    if(a[p] == card[j]){
                        sign = p;
                        break;
                    }
                }
                if(sign == 0){
                    a[top++] = card[j];
                }
                else{
                    for(int p = sign;p<=top;p++){
                        a[p] = 0;
                        top--;
                    }
                    a[top++] = card[j];
                }
            }bool vis[500000] = { };
            for(int j = 0;j<top;j++){

                if(vis[a[j]]==0){

                  ans[a[j]]++;
                  vis[a[j]] = 1;
                }
            }
        }

    for(int i = 1;i<=m;i++){
        cout << ans[i] << char(32);
    }
    return 0;
}
