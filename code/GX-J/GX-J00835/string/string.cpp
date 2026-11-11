#include<bits/stdc++.h>
using namespace std;
int n,s[1000];
char a[1000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        cin>>a[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        if(a[1]==a[2]){
            cout<<0;
            return 0;
        }
        if(s[1]>s[2]){
            cout<<s[2];
        }
        else{
            cout<<s[1];
        }
    }
    return 0;
}
