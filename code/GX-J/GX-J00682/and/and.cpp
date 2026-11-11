#include <stdc++.h>
using nam std;

int main(){
    int n,m,a[100],t,v;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            t=a[i] and a[j];
            v=a[j] and a[i];
            if (t<v){
                int c=v;
                v=t;
                t=v;
            }
        }
    }
    cout << t;
    return 0;
}
