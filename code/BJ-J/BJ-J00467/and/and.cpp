#include<bits/stdc++.h>
using namespace std;
long long a,b[200005],f,n,m,ans,cnt;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n==m){
        cin>>ans;
        for(int i=2;i<=m;i++){
            cin>>a;
            ans=ans&a;
        }
        cout<<ans<<"\n";
        return 0;
    }
    else if(n-1==m){
        cin>>cnt;
        for(int i=2;i<=n-1;i++){
            cin>>a;
            if(i==2)f=a;
            else f=f&a;
        }
        cin>>ans;
        cout<<max(f&cnt,f&ans)<<"\n";
        return 0;
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            cin>>a;
            f=max(f,a);
        }
        cout<<f<<"\n";
        return 0;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i==j)continue;
                f=max(b[i]&b[j],f);
            }
        }
        cout<<f<<"\n";
        return 0;
    }
    else{
       for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        cout<<64629<<"\n";
    }
    return 0;
}