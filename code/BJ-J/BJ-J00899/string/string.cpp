#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        long long a;
        cin>>a;
        char c;
        cin>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    long long j=s.size()-1;
    long long cnt=0;
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[j])cnt++;
        j--;
    }
    cout<<cnt;
    return 0;
}
