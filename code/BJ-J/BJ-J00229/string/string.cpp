#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",std);
    freopen("string.out","w",std);
    string s="";
    int l,n=0,c=0;
    cin>>l;
    for(int i=1;i<=l;i++){
        int f;
        char o;
        cin>>f>>o;
        n+=f;
        for(int j=1;j<=f;j++)
            s+=o;
    }
    for(int i=0;i<n-1/2;i++){
        if(s[i]!=s[n-1-i]){
            c++;
        }
    }
    cout<<c;
    return 0;
}

