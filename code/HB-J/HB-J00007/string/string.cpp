#include<bits/stdc++.h>
using namespace std;
char s[200005];
long long cnt;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int T;
        cin>>T;
        char c;
        cin>>c;
        for(int i=1;i<=T;i++){
            s[++cnt]=c;
        }
    }
    for(int i=1;i<=cnt;i++){
        if(s[i]==s[cnt+1-i]){
            continue;
        }else {

            ans++;
            s[cnt+1-i]=s[i];
        }
    }
    cout<<ans;
    return 0;
}
