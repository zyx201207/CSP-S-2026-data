#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,ans=0;
string L="";
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>T;
    while(T--){
        int n;
        char c;
        cin>>n>>c;
        while(n--)L+=c;
    }
    for(int i=0;i<(L.size()+1)/2;i++){
        if(L[i]!=L[L.size()-1-i])ans++;
    }
    cout<<ans;
}
