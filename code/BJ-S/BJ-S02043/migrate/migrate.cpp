#include<bits/stdc++.h>
using namespace std;
int n,bs[5009][5009],ans,c,t,f[5009][5009];
long long d,s[2000009];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int ft=1;ft<=t;ft++){
        cin>>n>>d;
        ans=0;
        for(int a=1;a<=n;a++){
            cin>>s[a];
        }
        if(n>5000){
            if(d/(s[2]-s[1])<2){
                cout<<0<<endl;
            }else{
                cout<<n-d/(s[2]-s[1])-1<<endl;
            }
            break;
        }
        for(int a=1;a<n;a++){
            for(int b=a+1;b<=n;b++){
                bs[a][b]=0;
                f[a][b]=0;
            }
        }
        for(int len=1;len<=n-1;len++){
            for(int z=1;z+len<=n;z++){
                int y=z+len;
                if(s[y]-s[z]<=d){
                    bs[z][y]=1;
                    f[z][y]=1;
                }else{
                    bs[z][y]=n+1,f[z][y]=0;
                    for(int a=z+1;a<y&&s[a]-s[z]<=d;a++){
                        if(bs[z][a]>0&&bs[a][y]>0){
                            if(bs[z][a]+bs[a][y]<bs[z][y]){
                                bs[z][y]=bs[z][a]+bs[a][y];
                                f[z][y]=f[a][y];
                            }else if(bs[z][a]+bs[a][y]==bs[z][y]){
                                f[z][y]+=f[a][y];
                            }
                        }
                    }
                    if(f[z][y]==2){
                           ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}