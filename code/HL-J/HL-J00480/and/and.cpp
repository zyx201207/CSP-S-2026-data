#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin >> n >> m;
    int num[n+5];
    for(int i = 1;i <= n;i++){
       cin >> num[i];
    }

    int mx = 0;
    if(m == 1){
        for(int i = 1;i <= n;i++){
            mx = max(num[i],mx);
        }
    }
    else if(m==2){
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;i++){
                mx = max(mx,num[i]&num[j]);
            }
        }
    }

    cout << mx;

    return 0;
}
