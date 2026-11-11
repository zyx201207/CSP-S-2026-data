#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
string s;
int l,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    int m;string a;
    cin>>m>>a;
    for(int j=0;j<m;j++){
        s+=a;
    }
    l+=m;
    }
    for(int i=0;i<(l)/2;i++){
        if(s[i]!=s[l-i-1]){
        ans++;
        }
    }
    cout<<ans;
    return 0;
}
