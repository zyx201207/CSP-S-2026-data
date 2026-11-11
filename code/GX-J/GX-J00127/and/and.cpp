#include <bits.stdc++.h>
using namespace std;
int n,m;
int main(){
    foren("and.in","r",stdin);
    foren("and.out","w",stdout);
    cin >> n >> m;
    int a[n];
    int b[m];
    for(int i=0;i<=n-1;i++){
        cin >> a[i];
    }
    for(int z=0;z<=n-1;z=z+2){
        for(int j=0;j<=m-1;j++){
            int x[j]=max(a[z],a[z+1])
            }
    }
    for(int h=0;h<=m-1;h++){
        int y=min(x[h],x[h+1])
    }
    cout << y;
    return 0;
}
