#include<bits/stdc++.h>
using namespace std;
int n,a,z,ans;
char b,s[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(int j=z;j<z+a;j++) s[j]=b;
        z+=a;
    }
    for(int i=0,j=z-1;i<ceil(z/2),j>=ceil(z/2);i++,j--){
        if(s[i]!=s[j]) ans++;
    }
    cout<<ans;
    return 0;
}
