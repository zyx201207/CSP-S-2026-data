#include<bits/stdc++.h>
using namespace std;
string s;
char ss;
int a,n,ans=0;
bool flag=true;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>ss;
        for(int j=0;j<a;j++){
            s+=ss;
        }
    }
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]){
            ans++;
            flag=false;
        }
    }
    if(flag){
        cout<<0;
        return 0;
    }
    else{
        cout<<ans;
        return 0;
    }
}
