#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s , s1,x,b;
    long long n;
    int a;
    cin>>n;


    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>s1;
        for(int j=1;j<=a;j++){
            s=s+s1;
        }
    }
    for(int i=s.size();i>=0;i--){
        b=s[i];
        x+=b;
    }
    //cout<<x;
    if(s==x){
        cout<<0;
        return 0;
    }
    if(n==1)cout<<0;return 0;
    return 0;
}
