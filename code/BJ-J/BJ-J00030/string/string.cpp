#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10;
int a[N];
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
    }
    int l = 0,r = n-1;
    long long cnt = 0;
    for(int i = 0;l<r;i++){
        if(a[l]>a[r]){
            if(b[l]!=b[r]) cnt+=a[r];
            if(b[l]!=b[r-1]) cnt+=(a[l]-a[r]);
            a[r-1]-=(a[l]-a[r]);
            l++,r--;
        }else if(a[l]<a[r]){
            if(b[l]!=b[r]) cnt+=a[l];
            if(b[l+1]!=b[r]) cnt+=(a[r]-a[l]);
            a[l+1]-=(a[r]-a[l]);
            l++,r--;
        }else{
            if(b[l]!=b[r]) cnt+=a[r];
            l++,r--;
        }
    }
    cout<<cnt;
    return 0;
}
