#include<bits/stdc++.h>
using namespace std;
long long n;
char x[10005],y[10005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long cnt=1;
    for(int i=1;i<=n;i++){
        long long a; cin>>a;
        char s; cin>>s;
        for(long long j=1;j<=a;j++){
            x[cnt]=s;
            cnt++;
        }
    }
    cout<<endl;
    for(long long i=cnt;i>=1;i--){
        y[cnt-i+1]=x[i];
    }
    long long ans=0;
    for(long long i=1;i<=cnt/2;i++){
        if(x[i]!=y[i]) ans++;
    }
    cout<<ans;
    return 0;
}
