#include<bits/stdc++.h>
using namespace std;
long long hw(string s){
    string g=s;
    long long cnt=0,len=s.size();
    reverse(s.begin(),s.end());
    for(int i=0;i<len/2;i++){
        if(s[i]!=g[i]){
            cnt++;
        }
    }
    return cnt;
}string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    vector<long long> a(n);
    vector<char> c(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    cout<<hw(s);
    return 0;
}
