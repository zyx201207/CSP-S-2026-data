#include <bits/stdc++.h>
using namespace std;

int n,m,a[1000000],b[1000000],ans[1000000],top=0;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=n-i+1;j<=n;j++){
            b[++top]=a[j];
            for(int k=1;k<=top;k++){
                if(a[j]==b[k]){
                    top=k;
                    break;
                }
            }
        }
        for(int j=1;j<=top;j++){
            ans[b[j]]++;
            b[j]=0;
        }
        top=0;
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
