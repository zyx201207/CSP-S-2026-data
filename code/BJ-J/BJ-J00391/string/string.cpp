#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string x;
        cin>>a>>x;
        for(int j=1;j<=a;j++){
            s+=x;
        }
    }
    if(s.size()%2==0){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1]){
                ans++;
            }
        }
        cout<<ans;
    }else{
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1]){
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
