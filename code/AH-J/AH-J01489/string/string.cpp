#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++){
        long long x;
        char a;
        cin>>x>>a;
        for(long long j=0;j<x;j++) s+=a;
    }
    long long j=0,sum=0;
    for(long long i=s.length()-1;i>=s.length()/2;i--){
        if(s[i]!=s[j]){
            sum++;
        }
        j++;
    }
    cout<<sum;
    return 0;
}
