#include<bits/stdc++.h>
using namespace std;
int n,m;
int l,r;
int a[1001];
int d[1001]; //操作次数
int t[1001];//第i次结果
int f[1001];//结果数组
int cnt;//跳过树组
int main(){
    //freopen(crystal.in,"r",stdin);
    //freopen(crystal.out,"w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cnt=0;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        t[i] = a[i];
    }
    sort(a,a+n);
    d[1] =0;
    for(int i = 2;i<=n-1;i++){
        for(int j = i-1;j>0;j--){
            if(a[i]-a[i-j]>0 && a[i-j]>cnt){
                d[i] += a[i]-a[i-j];
                t[i-j]+=d[i];
                f[t[i-j]]++;
            }
            if(a[i]-a[i-j]>m){
                cnt = a[i-1];
            }
        }
    }
    for(int i = 0;i<=n;i++){
        f[0] +=f[i];
    }
    cout<<f[0];
    return 0;
}
