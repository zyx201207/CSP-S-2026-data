#include<bits/stdc++.h>
using namespace std;
string w;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char s;
        cin>>x>>s;
        for(int j=1;j<=x;j++){
            w+=s;
        }
    }
    int ans=0,q=w.size();
    for(int i=0;i<(q-1)/2+1;i++){
        if(w[i]!=w[q-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
