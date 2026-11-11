#include<bits/stdc++.h>
using namespace std;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long s1;
        char c;
        cin>>s1;
        cin>>c;
        for(int j=1;j<=s1;j++)s+=c;
    }
    long long l=s.length();
    if(l%2==1){
        long long cnt1=0,cnt2=0;
        for(long long i=l/2+1;i<l;i++){
            if(s[i]!=s[l-i-1])cnt1++;
        }
        for(long long i=l/2-1;l>=0;l--){
            if(s[i]!=s[l-i-1])cnt2++;
        }
        cout<<min(cnt1,cnt2);
    }else{
        long long cnt1=0,cnt2=0;
        for(long long i=l/2;i<l;i++){
            if(s[i]!=s[l-i-1])cnt1++;
        }
        for(long long i=l/2-1;l>=0;l--){
            if(s[i]!=s[l-i-1])cnt2++;
        }
        cout<<min(cnt1,cnt2);
    }
    return 0;
}
