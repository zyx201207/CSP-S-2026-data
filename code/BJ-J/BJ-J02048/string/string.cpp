#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long l=1,r=0;
    long long cnt = 0;
    for(long long i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        r+=a;
        for(long long i=1;i<=a;i++){
            s+=c;
        }
    }
    while(l<=r){
        if(s[l]!=s[r]){
            cnt++;
            s[l]=s[r];
        }
        l++;
        r--;
    }
    cout<<cnt;
return 0;
}