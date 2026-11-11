#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in","r",stdin);
    //freoprn("string.out","w",stdout);
    int n;cin>>n;
    string s="";
    bool flag=1;char c[2005];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x>>c[i];
        c[0]=c[1];
        if(c[i]!=c[i-1])flag=0;
        for(int j=1;j<=x;j++){
            s+=c;
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(flag==1){
        cout<<0;
        return 0;
    }
    else cout<<2;
    return 0;
}
