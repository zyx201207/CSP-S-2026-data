#include<bits/stdc++.h>
using namespace std;

bool ju(string s){
    string sa=s;
    reverse(sa.begin(),sa.end());
    if(s==sa)return true;
    return false;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int a,n,ans=0;
    char c[200005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c[i];
        for(int j=0;j<a;j++){
            s=s+(char)c[i];
        }
    }
    string sa=s;
    reverse(sa.begin(),sa.end());
    if(s==sa){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]!=sa[i]){
            s[i]=sa[i];
            ans++;
            if(ju(s)){
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<ans;
    return 0;
}
