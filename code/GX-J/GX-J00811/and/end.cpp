#include<bits/stdc++.h>
using namespace std;
int a,b,c[2000005],mx=0,e=2,m=0;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin >> a >> b;
for(int i=1;i<=a;i++)cin >> c[i];
for(int i=1;i<=a;i++){
        e=i;
    for(int j=e;j<=a;j++){
        m=c[i]&c[j];
        max(mx,m);
    }
}
cout << mx;
return 0;
}
