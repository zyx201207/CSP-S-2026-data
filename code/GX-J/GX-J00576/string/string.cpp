#include<bits/stdc++.h>
using namespace std;

long long n,a[200005],ans=0,cnt=0;
string c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i]>>c[i];
    }
    if(n==1){
        cout<<"0";
        return 0;
    }
    if(n==2&&c[1]==c[2]){
        cout<<"0";
        return 0;
    }
    for(int i = 1; i <= n/2; i++){
        if(a[i]>a[n-i+1]-ans){
            cnt+=a[n-i+1]-ans;
            if(c[i]!=c[n-i]){
                ans+=a[i]-a[n-i+1];
                cnt+=ans;
            }
        }
        else if(a[i]==a[n-i+1]-ans){
            if(c[i]!=c[n-i+1]){
                cnt+=a[i];
            }
            ans=0;
        }
        else if(a[i]<a[n-i+1]-ans){
            ans=a[n-i+1]-ans-a[i];
            cnt+=a[i];
        }
    }
    cout<<cnt;

    return 0;
}
