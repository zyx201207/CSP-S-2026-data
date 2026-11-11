#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","w",stdin);
freopen("and.out","r",stdout);
int n,m,a[200000],dp[200000],num1=1,num2=1;
cin>>n>>m;
for (int i=0;i<n;i++){
   cin>>a[i];
}
if (m==1){
    int mx=a[0];
    for (int i=1;i<n;i++){
        if (a[i]>mx){mx=a[i];}
    }
    cout << mx;
}

else if(m==n){
    int sum=a[0];
    for (int i=1;i<n;i++){
        sum = (sum & a[i]);
    }
    cout << sum;
}

else if (m==2){
    int xm=-1;
    for (int kx=1;kx<=n-1;kx++){
        for (int i=0;i<=n-kx;i++){
            int now=a[i] & a[i+kx];
            if (now>xm){xm=now;}
        }
    }
    cout << xm;
}
else if (m==n-1){
    for (int i=0;i<n-1;i++)
        num1=num1 & a[i];
    for (int i=1;i<n;i++)
        num2=num2 & a[i]
     cout << max(num1,num2);
}

return 0;
}
