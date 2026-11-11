#include<bits/stdc++.h>
using namespace std;
long long n;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(long long j=1;j<=a;j++){
            s+=c;
        }
    }
    long long a1=0,a2=0;
    long long l=0 ,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]){
            a1++;
        }
        l++;
        r--;

    }

    cout<<a1;

    return 0;
}


