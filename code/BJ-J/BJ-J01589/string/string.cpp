#include<bits/stdc++.h>
using namespace std;
int n,a[100005],sum;
char c[100005];
string s,t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    for(int i=s.length()-1;i>=0;i--){
        t+=s[i];
    }
    for(int i=0;i<s.length();i++){
        if(s[i]!=t[i]){
            sum++;
            s[s.length()-i-1]=s[i];
        }
    }
    cout<<sum;
    return 0;
}