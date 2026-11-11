#include <bits/stdc++.h>
using namespace std;
string s2;
long long cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    string a;
    int n;
    long long x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>a;
        for(long long j=1;j<=x;j++){
            s+=a;
        }
    }

    for(long long i=s.length();i>=0;i--){
        s2+=s[i];
    }
    if(s==s2){
        cout<<"0";
        return 0;
    }
    else{
        long long l=0,r=s.length()-1;
        while(l<r){
            if(l==r){
                break;
            }
            if(s[l]!=s[r]){
                cnt++;
            }
            l++;
            r--;
        }
    }
    cout<<cnt;
    return 0;
}
