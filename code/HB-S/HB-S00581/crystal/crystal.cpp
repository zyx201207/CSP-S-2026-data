#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[1000086],s[1000086];
bool check(int len){
    for(int i=1;i<=n-len+1;i++){
        long long cos=0;
        cos=1ll*len*a[i+len-1];
        cos=cos-1ll*s[i+len-1]+1ll*s[i-1];
        if(cos<=m){
        //    cout << cos << ' ' << m <<' '<<len<< '\n';
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m; 
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<r){
        if(r-l==1){
            if(check(r))l=r;
            break;
        }
        int mid=l+((r-l)>>1);
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout << l;
    return 0;
}