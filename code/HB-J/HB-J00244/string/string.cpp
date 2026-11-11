#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],ans,mid,ca[200005],cntn=0;
char c[200005];
char s[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        ca[i]=a[i];
        for(int j=1;j<=a[i];j++){
            s[cntn+j]=c[i];
        }
        cntn+=a[i];
    }
    mid=cntn/2;
    for(int i=1;i<=mid;i++){
        if(s[i]!=s[cntn-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
