#include <bits/stdc++.h>
using namespace std;
long long n,g;
string s;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>g>>c;
        for(long long j=1;j<=g;j++){
            s=s+c;
        }
    }
    long long ans=0;
    for(long long i=0;i<=s.size()/2-1;i++){
        if(s[i]!=s[s.size()-i-1]){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
