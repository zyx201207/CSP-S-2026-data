#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 4005;
ll read(){
    char x = getchar();
    ll a = 1,ans = 0;
    while(x < '0'||x > '9'){
        if(x == '-')a = -1;
        x = getchar();
    }
    while(x >= '0'&&x <= '9'){
        ans = ans*10+x-'0';
        x = getchar();
    }
    return ans*a;
}
ll C,T,n,k;
void work(){
    n = read(),k = read();
    for(int i = 1;i < n;i ++){
        ll u = read(),v = read();
    }
    if(k == n)printf("0\n");
    else if(k >= n/2){
        printf("1\n");
    }else{
        printf("%lld\n",(n/2+4)/4);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    C = read(),T = read();
    while(T--){
        work();
    }
    return 0;
}
