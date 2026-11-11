#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans[35],x[200005],s[200005],uu=1,anss;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[i]=1;
    }
    for(int i=29;i>=0;i--){
        for(int j=1;j<=n;j++) s[j]=x[j];
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(!((a[j]>>i)&1)) x[j]=0;
            if(x[j]==1) cnt++;
        }
        if(cnt>=m) ans[i]=1;
        else{
            ans[i]=0;
            for(int j=1;j<=n;j++) x[j]=s[j];
        }
    }
    for(int i=0;i<=29;i++){
        anss+=ans[i]*uu;
        uu*=2;
    }
    cout<<anss;
    return 0;
}

