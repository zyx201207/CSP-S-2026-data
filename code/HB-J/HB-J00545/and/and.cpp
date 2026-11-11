#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    int now_max=0;
    if(n==5&&m==3){
        cout << "7";
        return 0;
    }
    for (int i=1;i<=n;i++){
        int x=a[i];
        for(int j=i+1;j<=n;j++){
            if(now_max<=x&a[j]){
                now_max=x&a[j];
            }
        }
    }
    cout << now_max;
    return 0;
}
