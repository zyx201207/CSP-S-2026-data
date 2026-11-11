#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long n;
long long a[200005];
long long ans;
bool flag=true;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=2;i<=n;i++){
        if(c[i]!=c[i-1]) flag=false;
    }
    if(flag)
    {
        cout<<0;
        return 0;
    }
    if(n==1) cout<<0;
    else{
        for(int i=1;i<=n/2;i++){
            if(c[i]==c[n-i+1])
            {
                ans+=a[n-i+1]-a[i];
            }
            else ans+=a[i];
        }
    }
    cout<<abs(ans);
    return 0;
}