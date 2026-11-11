#include<bits/stdc++.h>;
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a1,sum=0,v=0;
    string s="",b1;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a1>>b1;
        for(long long j=1;j<=a1;j++){
            s+=b1;
            v++;
        }
    }
    for(long long i=0;i<(v/2+v%2);i++){
        if(s[i]!=s[v-i-1]) sum++;
    }
    cout<<sum;
    return 0;
}