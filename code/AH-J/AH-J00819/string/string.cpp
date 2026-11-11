#include<bits/stdc++.h>
using namespace std;
long long a,ans;
char ch;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>ch;
        for(int j=1;j<=a;j++){
            s=s+ch;
        }
    }
    int l=s.size();
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}



