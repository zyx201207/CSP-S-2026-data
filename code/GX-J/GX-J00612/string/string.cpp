#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i]>>c[i];
    }
    int ll=1, rl=n;
    int lk=a[1], rk=a[n];
    while(ll<rl){
        if(c[ll]!=c[rl]){
            int minn = min(lk,rk);
            sum+=minn;
            lk-=minn;
            rk-=minn;
        }else{
            int minn = min(lk,rk);
            lk-=minn;
            rk-=minn;
        }

        if(lk==0){
            ll++;
            lk=a[ll];
        }
        if(rk==0){
            rl--;
            rk=a[rl];
        }
    }
    cout<<sum;
    return 0;
}
