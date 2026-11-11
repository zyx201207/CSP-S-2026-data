#include <bits/stdc++.h>
using namespace std;
int a[1000010],mi[1000010];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        for(int i=1;i<=n;i++){
            for(int j=n;j>=i;j--){
                mi[a[j]]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<mi[i]<<' ';
    }
    return 0;
}
