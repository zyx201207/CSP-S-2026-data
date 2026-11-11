#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r"stdin);
    freopen("string.out","w"stdout);
    long long n;
    lomg long a;
    char c;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s=s+c;
        }
    }
    int l=s.size(),cnt=0;
    for(int i=0;i<l;i++){
        if(s[i]==s[l-1]){
            l--;
        }else{
            cnt++;
            l--;
        }
    }
    cout<<cnt;
    return 0;
}
