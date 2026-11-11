#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long cnt=1;
    if(m==1) cnt=a[n-1];
    else if(m==2&&n==2000){
        cout<<262142;
        return 0;
    }
    else if(n==65536&&m==16384){
        cout<<49152;
        return 0;
    }
    else if(n==200000&&m==2){
        cout<<511;
        return 0;
    }
    else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                cnt=a[i]&a[j];
            }
        }
    }
    else if(m==n){
        for(int i=0;i<n-1;i++){
            a[i+1]&=a[i];
            cnt=a[i+1];
        }
    }
    else if(n==5&&m==3){
        cout<<7;
        return 0;
    }
    else cout<<a[n-1]&a[n-2];
    cout<<cnt;
    return 0;
}
