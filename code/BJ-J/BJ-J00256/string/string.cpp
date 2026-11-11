#include<bits/stdc++.h>
using namespace std;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;cin >> n;
    int st=0;
    for(int i = 1;i <= n;i++){
        long long a;cin >> a;
        char c;cin >> c;
        for(long long j = 1;j<= a;j++){
            s+=c;
        }
    }
    long long cnt=0;
    for(int i = 0;i < s.length()/2+1;i++){
        int j=s.length()-i-1;
        if(s[i]!=s[j]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
