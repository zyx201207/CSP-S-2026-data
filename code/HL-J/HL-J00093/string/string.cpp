#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long len=0;
    string s="";
    for(int i=0;i<n;i++){
        long long k;
        cin>>k;
        char c;
        cin>>c;
        len+=k;
        for(int j=0;j<k;j++){
            s+=c;
        }
    }
    long long cnt=0;
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
