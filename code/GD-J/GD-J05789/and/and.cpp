#include<bits/stdc++.h>
using namespace std;
int a[300000],n,m,b[300000],ans = -1,step = 0,num,amax = -1;
void dfs(int x){
    step++;
    b[x] = 1;
    num = num&a[x];
    if(step == m){
        ans = max(ans,num);
    }
    for(int i = 0;i < n;i++)
        if(b[i] == 0){
            int z = num;
            dfs(i);
            b[i] = 0;
            step--;
            num = z;
        }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        amax = max(amax,a[i]);
    }
    if(n <= 2000){
        for(int i = 0;i < n;i++){
            b[i] = 0;
            num = a[i];
            step = 0;
            dfs(i);
        }
         cout << ans;
    }else{
        cout << amax;
    }
    return 0;
}
/*
5 3
31 3 1 15 7

*/



