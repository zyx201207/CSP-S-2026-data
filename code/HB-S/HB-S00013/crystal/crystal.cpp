#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long  a[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    bool p=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)p=0;
    }
    bool q=0;
    b[1]=0;
    int x;
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
        if(i==2) x=b[2]-b[1];
        if(b[i]-b[i-1]!=x)q=1;
    }
    if(p||!q){
            long long k;
        for(int i=1;i<=m;i++)k+=b[i];
    cout<<k;
    }
    else{
     sort(a+1,a+n+1);
    bool fq=0;
    long long f=-0x3f3f3f;
    long long y=0;
    for(int i=n;i>=1;i--){
        int t=0;
       int u=i;
       y=0;
        for(;;){
                if(u==0)fq=1;
            if(t>=m||u==0)break;
            for(int j=u;j<=i;j++){t+=b[j];if(t>m){break;y=0x3f3f3f;}}
            u--;
             y++;
    }
    //cout<<endl;
    if(fq==1)y++;
    f=max(f,y);
}
cout<<f;
    }
}
