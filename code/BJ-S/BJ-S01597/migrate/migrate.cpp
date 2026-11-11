#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int l1, l2;
vector<int> x(n + 4);
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int i = 0;i < t;i++){
        cin >> n >> d;
        for(int j = 0;j < n;j++){
            cin >> x[j];
        }
        for(int s = 0;s < t;s++){
            if(s > 0){
                if(x[s] - x[s-d] <= d){
                    if(i == 0){
                        l1++;
                    }l2++;
                }
            }continue;
        }
    }
    if(l2 > 2){
        l2 = 0;
    }
    if(l1 > 2){
        l1 = 0;
    }
    cout << l1 << "\n" << l2;
    return 0;
}