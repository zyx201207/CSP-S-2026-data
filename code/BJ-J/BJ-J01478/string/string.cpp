#include<bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
int main(){
    int n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    if(n==1){
        cout << 0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    long long cnt=0;
    int l=1,r=n;
    while(l<r){
        if(a[l]>a[r]){
            if(b[l]!=b[r])cnt+=a[r];
            a[l]-=a[r];
            a[r]=0;
            r--;
        }else if(a[r]>a[l]){
            if(b[l]!=b[r])cnt+=a[l];
            a[r]-=a[l];
            a[l]=0;
            l++;
        }else{
            if(b[l]!=b[r])cnt+=a[l];
            a[l]=a[r]=0;
            l++;
            r--;
        }
    }
    cout << cnt;
    return 0;
}

