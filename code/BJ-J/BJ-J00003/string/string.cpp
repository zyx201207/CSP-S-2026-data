#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    string s;
    int n,a,cnt=0,sum=0;cin>>n;
    char c;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        cnt+=a;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    for(int i=0;i<=cnt/2;i++){
        if(s[i]!=s[cnt-i-1])sum++;
    }
    cout<<sum;
}