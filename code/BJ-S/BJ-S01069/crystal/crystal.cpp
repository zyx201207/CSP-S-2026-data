#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m;
    int n;
    long long cmt;
    long long a[500010];
    int b=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        long long c=0;
       for(int j=i-1;j>=0;j--){
           c+=a[i]-a[j];
            if(c>m){
            b=max(b,i-j);
            break;
       }
            if(j==0){
                b=i+1;
            }
    }
    }
    cout<<b;

    return 0;
}
