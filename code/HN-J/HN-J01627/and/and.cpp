#include<bits/stdc++.h>
using namespace std;
int a[100010],b,c,d,x;
char ax,bx;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        a[0]=a[i]&a[i-1];
    }
    cout<<a[0];
    return 0;
}

































//莪緟甡了，這①丗我穿越到了一个物价上涨10000倍的
