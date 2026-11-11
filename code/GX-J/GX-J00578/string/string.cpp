#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int a,w,t=0,e=0,f=0;
    char c;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>w>>c;
        for(int j=0;j<w;j++){
            s[t]=1;
            t++;
        }
        e+=w;

    }
    for(int i=0;i<e;i++){
        for(int j=e;j>0;j--){
            if(s[i]==s[j])f++;
        }
    }
    if(f%2==1)cout<<s;
    return 0;

}
