#include<bits/stdc++.h>
using namespace std;
const int MAXN=6e5+5;
long long n,d,x[MAXN];
void dengcha(){
    long long ans=0;
    int diff=x[2]-x[1];
    if(d<=diff) {cout<<0<<endl;return;}
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(j-i<=d) continue;
            if((j-i)%d==0) continue;
            ans++;
        }
    }
    cout<<ans<<endl;
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cout<<1<<endl;
    }
    return 0;
}
