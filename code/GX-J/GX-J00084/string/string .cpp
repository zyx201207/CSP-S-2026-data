#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(long long j=1;j<=a;j++){
            s+=c;
        }
    }
    long long cnt=0;
    for(long long i=0;i<=s.size()-1;i++){
        long long b1=0,b2=s.size()-1;
        if(s[b1]==s[b2]){
            b1++;
            b2--;
        }
        else{
            cnt++;
            b1++;
            b2--;
        }
    }
    cout<<cnt/2;
    return 0;
}

