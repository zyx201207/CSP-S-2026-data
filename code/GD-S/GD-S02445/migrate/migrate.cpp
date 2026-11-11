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
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long min_f=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) {cin>>x[i];min_f=min(min_f,x[i]-x[i-1]);}
        if(d>=x[n]-x[1]&&n!=2) {cout<<0<<endl;continue;}
        if(d<=min_f) {cout<<0<<endl;continue;}
        if(c==11||c==12) dencha();
        else cout<<1;
    }
    return 0;
}
