#include <bits/stdc++.h>
using namespace std;
struct str{
    long num;
    char zm;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    str ls[200005];
    for(int i = 1;i <= n;i++){
        cin >> ls[i].num >> ls[i].zm;
    }
    int l = 1, r = n;
    long ans = 0;
    while(l < r){
        if(ls[l].zm != ls[r].zm){
            if(ls[l].num > ls[r].num){
                ls[l].num -= ls[r].num;
                ans += ls[r].num;
                r--;
            }
            else if(ls[l].num == ls[r].num){
                ans += ls[r].num;
                r--;
                l++;
            }
            else {
                ls[r].num -= ls[l].num;
                ans += ls[l].num;
                l++;
            }
        }
        else{
            if(ls[l].num > ls[r].num){
                ls[l].num -= ls[r].num;
                r--;
            }
            else if(ls[l].num == ls[r].num){
                r--;
                l++;
            }
            else {
                ls[r].num -= ls[l].num;
                l++;
            }
        }
    }
    cout << ans;
    return 0;
}
