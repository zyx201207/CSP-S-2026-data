#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w")
    int n,m;
    cin >> n >> m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cout << a[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
