#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m,y;
    int x[10000005];
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int s=0;s<n;s++){
        for(int j=s;j<s+m-2;j++){
            y=max((x[j]&x[j+1]),(x[j]&x[j+2]));
        }
    }
    cout << y;
}
