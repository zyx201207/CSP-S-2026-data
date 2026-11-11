#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    reopen("string","w",stdout);
    int n,w;
    long s1=0,s2=0;
    int a[1000000]={};
    string b;
    char q;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w;
        a[i]=w;
        cin>>q;
        b[i]=q;
    }
    if(n%2!=0){
        n=n-1;
    }
    for(int x=1;x<=n/2;x++){
        if(b[x]!=b[n-x+1]){
            s1=a[x]+s1;
            s2=a[n-x+1]+s2;
        }
    }
    if(s1>s2){
        cout<<s1;
    }
    else{
        cout<<s2;
    }
    return 0;
}
