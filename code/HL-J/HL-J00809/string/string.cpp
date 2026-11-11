#include<bits/stdc++.h>
using namespace std;
string s;
long long n,ai;
char c;
int hui_wen(string s){
    long long longen=s.size();
    long long ci=0;
    long long gai=0;
    if(longen%2==1){
        ci=longen/2+1;
    }
    else{
        ci=longen/2;
    }
    for(int i=0;i<ci;i++){
        if(s[i]!=s[longen-1-i]){
            gai++;
        }
    }
    return gai;

}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ai>>c;
        for(int j=1;j<=ai;j++){
            s+=c;
        }
    }
    long long ans=hui_wen(s);
    cout<<ans;
    return 0;
}
