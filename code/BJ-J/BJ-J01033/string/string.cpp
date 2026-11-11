#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int M=1e6+10;
char t[M];
long long j;

long long now,ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    /*if(n==1){
        cout<<0;
        return 0;
    }*/
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(long long k=1;k<=a;k++){
            t[++j]=c;
        }
    }
    for(int i=1;i<=ceil(j/2);i++){
        if(t[i]!=t[j+1-i]) ans++;
    }
    cout<<ans;

    /*int j=1;
    while(j<=n/2){
        if(s[j].c!=s[n+1-j].c){
            ans+=s[n+1-j].a;
            //cout<<ans<<" "<<j<<" "<<now<<endl;
        }
        now+=min(s[n+1-j].a,s[j].a);
        if(now>=s[j].a){
            now-=s[j].a;
            j++;
            s[j].a-=now;
            now=0;
        }
    }
    cout<<ans;*/
    return 0;
}
