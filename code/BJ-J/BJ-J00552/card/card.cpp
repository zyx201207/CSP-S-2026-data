#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans = 0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= m; j++){
            if(i==j){
                ans += k;
                continue;

            }else{
                ans=k;
                break;

            }

        }
    }
    return 0;


}
