#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    int k;
    char r;
    cin>>k>>r;
    for(long long j=cnt+1;j<=cnt+k;j++){
        s[j]=r;
        }
        cnt+=k;
    }
    for(long long i=1;i<=cnt/2;i++){
        if(s[i]!=s[cnt+1-i]){
        ans++;
        }
    }
    cout<<ans;

    return 0;
}
