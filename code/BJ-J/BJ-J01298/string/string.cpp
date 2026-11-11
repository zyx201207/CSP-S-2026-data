#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n;
    int cnt=0;
    cin>>n;
    int a;
    char c,b[5000000];
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            b[cnt]=c;
            cnt++;
        }
    }
    int ans=0;
    cnt--;
    for(int i=0;i<=floor(cnt*0.5);i++){
        if(b[i]!=b[cnt-i])ans++;
    }
    cout<<ans;
}
