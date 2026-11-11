#include<bits/stdc++.h>
using namespace std;
int n,a[100010],l=0,ans=0;
string c[100010],sums="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            sums+=c[i];
        }
    }
    for(int i=1;i<=n;i++){
        l+=a[i];
    }
    for(int i=0;i<(l+1)/2;i++){
        if(int(sums[i])!=int(sums[l-i-1])) ans+=1;
    }
    cout<<ans;
    return 0;
}

