#include<bits/stdc++.h>
using namespace std;
const int MAXn = 2e5+10;
int n,a[MAXn],m,ans = 0;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&a[i]);
    }
    if(m == 2){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(i != j ) ans = max(ans,a[i]&a[j]);
            }
        }
    }
    if(m == 3){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                for(int i1 = 1 ; i1 <= n ; i1++){
                    if(i != j && i != i1) ans = max(ans,(a[i]&a[j])&a[i1]);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
