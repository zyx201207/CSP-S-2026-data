# include <bits/stdc++.h>
using namespace std;
long long m;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>m;
    for(long long i=0;i<m;i++){
        long long q;
        cin >>q;
        string w;
        cin >>w;
        for(long long i=0;i<q;i++){
            s=s+w;
        }
    }
    long long ans=0;
        for(long long i=0;i<s.size()/2;i++){
            if(s[i]!=s[i+s.size()/2]){
                ans++;
            }
        }
    cout <<ans;
    return 0;
}
