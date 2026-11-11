#include <bits/stdc++.h>>
using namespace std;

int n,m,w=0;
int main(){
//freopen("and.in","r",stdin);
//freopen("and.out","w",stdout);
cin >> n >> m;
int a[n+10];
for(int i=1;i<=n;i++){
    cin >>  a[i];
}

for(int i=1;i<=n-m+1;i++){
    int idv = a[i];
    for(int k=0;k<=n-m;k++){
    for(int j=1;j<m;j++){
    idv = idv&a[i+j+k];
    }
    if(idv >= w)
        w = idv;
}}
cout << w;

return 0;
}
