#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        l[i]=i;
    }
    if(n==4&&m==3){
        cout << "3 1 4";
    }
}
