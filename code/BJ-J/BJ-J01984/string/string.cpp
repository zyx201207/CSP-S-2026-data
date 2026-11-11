#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e5+5;
int n;
long long cnt,ct,ans;
long long s[N],k[N],f[M];
char p[N],h[M];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>p[i];
        cnt+=s[i];
        k[i]=cnt;
        //cout<<k[i]<<endl;
    }
    //cout<<cnt<<endl;
    for(int i=1;i<=n;i++){
        f[++ct]=k[i];
        if(k[i]!=cnt)f[++ct]=cnt-k[i];
    }
    sort(f+1,f+1+ct);
    /*for(int i=1;i<=ct;i++){
        cout<<f[i]<<" ";
    }
    cout<<endl;*/
    int m=unique(f+1,f+1+ct)-f-1,zz=0;
    for(int i=1;i<=m;i++){
        if(f[i]>k[zz])zz++;
        h[i]=p[zz];
        //cout<<f[i]<<":"<<h[i]<<endl;
    }
    //cout<<endl;
    for(int i=1;i<=m/2;i++){
        if(h[i]!=h[m-i+1]){
            ans+=(f[i]-f[i-1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
