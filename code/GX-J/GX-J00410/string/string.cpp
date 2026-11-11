#include <bits/stdc++.h>
using namespace std;
int n;

long long a[200005];
long long dif=0,ans;
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(int i =1;i<=n;i++){
        cin>>a[i]>>b[i];

    }


    for(int i =1;i<=n/2;i++){
        if(b[i]!=b[n-i+1]) {
        ans+=a[i];}
    }
    cout<<ans;

    return 0;
}
