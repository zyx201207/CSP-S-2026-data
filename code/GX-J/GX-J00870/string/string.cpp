#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
int main(){

     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<3;i++){
        long long x;
        char h;
        cin>>x>>h;
        for(int i=0;i<x;i++){
            s+=h;
        }
    }
    long long ans=0;
    long long zx=s.size();
    for(int i=s[0];i<zx;i++){
        if(s[i]==s[zx]){
            zx--;
            continue;
        }
        else{
            ans++;
            zx--;
        }
        cout<<ans<<endl;
}
    cout<<ans<<endl;
   return 0;
}
