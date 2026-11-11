#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[300001],ton[300001],b[300001];
signed main (){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    int len = 0;
    for(int i  = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            bool falg = false;
            ton[a[i]]++;
            if(ton[a[i]]>1){
                for(int k = 1;k <= len;k++){
                    if(b[k] == a[i])falg = true;
                    if(falg)b[len--] = 0;
                }
            }
            b[++len] = a[i];
        }
    }
    for(int i = 1;i <= len;i++){
        cout<<b[len]<<" ";
    }
    return 0;
}
