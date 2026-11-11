#include<bits/stdc++.h>
using namespace std;
int n,m;
int flag[500005];
long long z[500005];
long long ans[300005];
long long a[500005];
long long top;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j<=n;j++){
            if(flag[a[j]] == 0){
                flag[a[j]] = 1;
                z[top] = a[j];
                top++;
            }
            else{
                while(2 > 1){
                    top--;
                    if(z[top]=a[j]){
                        break;
                    }
                    flag[z[top]] = 0;
                }
            }
        }
        for(int i = 0;i < top;i++){
            cout << z[i]<<endl;
            ans[z[i]]++;
        }
        for(int i = 1;i <= n;i++){
            flag[i] = 0;
        }
        top = 0;
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
