#include<bits/stdc++.h>
using namespace std;
char a[200005];
int b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n; cin>>n;
    long long sum=0,cnt=0;
    for(int i=1; i<=n; i++){
        cin>>b[i]>>a[i];
        sum+=b[i];
    }
    char c[sum+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=b[i]; j++){
            cnt++;
            c[cnt]=a[i];
        }
    }
    long long ans=0;
    for(int i=1; i<=sum/2; i++)
        if(c[i]!=c[sum-i+1])
            ans++;
    cout<<ans;
    return 0;
}
