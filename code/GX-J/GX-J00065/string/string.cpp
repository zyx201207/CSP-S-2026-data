#include<bits/stdc++.h>
using namespace std;
string s;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long a;
        char b;
        cin>>a>>b;
        for(long long j=1;j<=a;j++){
            s+=b;
        }
    }
    long long cnt=0;
    for(long long i=0;i<=s.size();i++){
        long long c=0,d=s.size()-1;
        if(s[c]==s[d]){
            c++;
            d--;
        }else{
            cnt++;
            c++;
            d--;
        }
    }
    cout<<cnt/2;

    return 0;
}
