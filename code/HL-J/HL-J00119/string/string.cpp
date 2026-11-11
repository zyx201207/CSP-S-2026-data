#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c=0,p=0;
    cin>>n;
    char x[n];
    int s[n],t=0;
    for(int i=0;i<n;i++){
        cin>>s[i]>>x[i];
        t+=s[i];
    }
    int l[t];
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i];j++){
            l[p]=int(x[i]);
            p++;
        }
    }
    for(int i=0;i<t/2;i++){
        if(l[i]!=l[i+t/2])c++;
    }
    cout<<c;
    return 0;
}
