#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int a[int(1e7+100)];
bool c[int(1e7+100)];
int m = 0,n = 0;
int f(int res,int x) {
    if(x == m) return res;
    for(int i = 1;i<=n;i++) {
        if(c[i] == false) {
            int xxx = (res&a[i]);
            int tmp = f(xxx,x+1);
            if(tmp<res)return res;
            else {
                c[i] = true;
                return tmp;
            }
        }
    }
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>> n>> m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    int res = 0;
    for(int i = 1;i<=n;i++) {
        for(int i = 1;i<=n;i++)c[i] = false;
        res = max(res,f(i,1));
    }
    cout<< res;
    return 0;
}
