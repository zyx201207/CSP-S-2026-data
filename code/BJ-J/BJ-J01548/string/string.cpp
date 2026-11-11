#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++) {
                s+=c;
        }
    }
    int len=s.length(),cnt=0;
    if(len%2==1){
        for(int i=len/2,j=len/2;i>=1&&j<=n;i--,j++){
            if(s[i]!=s[j]) cnt++;
        }
    }
    if(len%2==0){
        for(int i=len/2-1,j=len/2;i>=1&&j<=n;i--,j++){
            if(s[i]!=s[j]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
