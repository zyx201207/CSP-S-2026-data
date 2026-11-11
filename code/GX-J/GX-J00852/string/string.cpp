#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int b=0;

    string s="",s2="";
    for(int i=1;i<=n;i++){
        int a;
        char a1;
        cin>>a>>a1;
        s+=a*a1;
        b+=a;

    }

    for(int i=b-1;i>=0;i--){
        s2+=s[i];

    }

    if(s==s2){
        cout<<0;
    }
return 0;
}
