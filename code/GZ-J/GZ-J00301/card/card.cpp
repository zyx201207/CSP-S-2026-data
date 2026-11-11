//GZ-J00301-观山湖区第八中学-金煜文
#include <bits/stdc++.h>
using namespace std;
int n,sum[500010],m,a[500010],desk[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s=1,w=1;
    while(s!=n){
        desk[w]=a[s];
        w++;
        s++;
        for(int i=1;i<w;i++){
            if(desk[w]==desk[i]){
                w=1;
                break;
            }
            sum[desk[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
