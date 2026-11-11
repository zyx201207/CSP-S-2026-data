#include <iostream>
using namespace std;
const int N = 1e5;
int a[N], n, r, arr[N];
int ans = 0;
void dfs(int dep){
    if(dep ==r+1){
        int last = arr[a[1]];
        int sum = 0;
        for(int i = 2; i <= r; i++){
            sum = last & arr[a[i]];
            last = sum;
        }
        ans = max(ans,sum);
        return;
    }
    for(int i = a[dep-1]+1; i <= n; i++){
        a[dep] = i;
        dfs(dep+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>r;
    for(int i = 1; i <= n; i ++){
        cin>>arr[i];
    }
    dfs(1);
    cout<<ans<<endl;
}

