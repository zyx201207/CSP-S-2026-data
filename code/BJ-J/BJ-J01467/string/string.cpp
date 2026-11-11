#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0,ccnntt=0;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        cnt+=a;
        while(a--){
            s+=c;
        }
    }cnt--;
    for(int i=0;i<=cnt/2;i++){
        if(s[i]!=s[cnt-i]){
            ccnntt++;
        }
    }
    cout<<ccnntt;
    return 0;
}

