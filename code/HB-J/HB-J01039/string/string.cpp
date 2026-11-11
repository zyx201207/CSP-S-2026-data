#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    char c;
    int ans=0;
    string s;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s=s+c;
        }
    }
    int l=s.size();
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
