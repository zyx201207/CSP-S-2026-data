#include <bits/stdc++.h>
using namespace std;
int n,a[200010],l;
char c[200010];
char ch(int num){
    if(num <= a[1]) return c[1];
    int tt = a[1];
    for(int i = 2;i <= n;++i){
        tt += a[i];
        if(num <= tt) return c[i];
    }
    return '.';
}
int huiwen(){
    int t = n / 2 + 1,ans1 = 0,ans2 = 0;
    for(int i = 1;i <= t;++i){
        if(ch(i) != ch(l + 1 -i)) ++ans1;
    }
    t = n / 2 - 1;
 
   return ans1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;++i){
        cin>>a[i]>>c[i];
        l += a[i];
    }
    cout<<huiwen();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
