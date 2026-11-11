#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    string s,ss,sss;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        string sa;
        cin>>a>>sa;
        for(int j=0;j<a;j++){
            s+=sa;
        }
    }
    int sum=0;
    for(int i=s.length()-1;i>=0;i--){
        ss[sum]=s[i];
        sss+=ss[sum];
        sum++;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]!=sss[i]){
            ans++;
        }
    }
    cout<<ans/2;
    return 0;
}