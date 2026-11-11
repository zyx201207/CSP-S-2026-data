#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    long long cnt=0;
    while(l<=r){
        if(a[l]>a[r]){
            if(c[l]!=c[r])cnt+=a[r];
            a[l]-=a[r];
            r--;
        }
        else if(a[l]<a[r]){
            if(c[l]!=c[r])cnt+=a[l];
            a[r]-=a[l];
            l++;
        }
        else{
            if(c[l]!=c[r])cnt+=a[r];
            l++;
            r--;
        }
    }
    cout<<cnt;
    return 0;
}