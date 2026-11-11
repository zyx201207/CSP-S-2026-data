#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,op,ans;
char c;
string s,sp;
signed main(){
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op>>c;
        for(int j=1;j<=op;j++){
            s+=c;
            sp=c+sp;
        }
    }
    //cout<<s<<" "<<sp<<endl;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=sp[i]) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
