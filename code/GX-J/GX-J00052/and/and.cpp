#include <bits/stdc++.h>;
using namespace std;
int a[10000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int m,n,mx=0;
cin >>n >>m;
for(int i=1;i<=n;i++) cin >>a[i];
sort(a+1,a+1+n);
if (m==1) {
    for(int i=1;i<=n;i++){
        mx = max(a[i],mx);
    }
}
if (m==2){
for(int i=1;i<=n;i++){
    int cnt=0;
    for(int k=i;k<=n;k++){
    cnt = max(a[i]&a[k],cnt);
    }
    mx = max(cnt,mx);
    }
}
if (m==3){
for(int i=1;i<=n;i++){
    int cnt1=0;
    for(int k=i;k<=n;k++){
            int op=0;
        for(int l=k;l<=n;l++){
            op = max(a[i]&a[k]&a[l],op);
        }
        cnt1 = max(op,cnt1);
    }
    mx = max(cnt1,mx);
}
}
cout << mx;
return 0;
}
