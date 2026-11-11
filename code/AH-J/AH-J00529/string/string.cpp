#include <bits/stdc++.h>
using namespace std;
long long n,a[10005];
string s,w,p;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>w;
        for(int i=1;i<=a[i];i++){
                s+=w;
        }
    }
    for(int i=1;i<n;i++){
        if(w[i]==w[i+1]){
            cout<<0;
            return 0;
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    else if(s[1]==s[n]&&s[a[1]]==s[n-a[n]]){
        cout<<0;
        return 0;
    }
    else{
        cout<<2;
        return 0;
    }
    return 0;
}
