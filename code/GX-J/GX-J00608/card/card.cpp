#include <bits/stdc++.h>
using namespace std;

int n,m,b[500005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin >> n >> m;
int a[n+10];
for(int i=1;i<=n;i++){
    cin >> a[i];
}

for(int i=2;i<=n;i++){
    for(int j=i-1;j<=n;j++){
        if(a[j] in b){
        for(int k=j;j<=0;j--){
            if(b[k]==a[j]){
                b[k]=0;
                return;
                }
            b[k]=0;
            }}
        else{
            b[j]=a[j];
        }}
    for(int l=i-1;l<=n;l++){
        if(b[l]==0) continue;

    }

}

for(int i=1;i<=m;i++){
    cout<<
}

return0;
}
