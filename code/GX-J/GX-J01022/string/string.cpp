#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005];
    string c[200005],s;
    char x[200005],y[200005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int len=s.size();
    for(int i=0;i<len/2;i++){
        x[i]=s[i];
    }
    for(int i=len-1,j=0;i>=len/2;i--,j++){
        y[j]=s[i];
    }
    int ans=0;
    for(int i=0;i<len/2;i++){
        if(x[i]!=y[i]) ans++;
    }
    cout<<ans;
    return 0;
}
