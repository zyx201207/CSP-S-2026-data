#include<bits/stdc++.h>
using namespace std;
#define int long long
char c;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n,t=0,ans=0,a;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=t;j<a+t;j++){
            s[j]=c;
        }
        t+=a;
    }
    int d=t/2;
    if(t%2==1){
    for(int i=0;i<d;i++){
        if(s[i]!=s[t-1-i])ans++;
    }
    }else{
        int b=d-1;
        for(int i=0;i<b;i++){
            if(s[i]!=s[t-1-i])ans++;
        }
        if(s[b]!=s[d])ans++;
    }
    cout<<ans;
    return 0;
}
