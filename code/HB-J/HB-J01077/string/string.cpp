#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,i,j,ans=0,s=0,a;
    char x;
    string b;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a>>x;
        s+=a;
        for(j=1;j<=a;j++){
            b=b+x;
        }
    }
    if(s/2==0){
        for(i=1;i<=s/2;i++){
            if(b[s/2-i]!=b[s/2+i-1]){
                ans++;
            }
        }
    }
    else{
        for(i=1;i<=s/2;i++){
            if(b[s/2-i]!=b[s/2+i]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
