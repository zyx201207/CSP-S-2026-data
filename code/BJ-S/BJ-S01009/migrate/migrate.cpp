#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000009];
int main(){
freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
    cin>>n>>d;
    for(int j=1;j<=n;j++){
    cin>>x[j];

    }
    if(c==11 or c==12){
    long long ji=x[2]-x[1];

    long long h=d/ji;
    long long hh=2*h-1;
    cout<<n-1-hh+1<<endl;

    }
    if(c==13 or c==14){
            long long zuo,you,zh,zong=0;
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(x[k]-x[j]>d){
                    zuo=j,you=k;
                    zh=(zuo+you+1)>>1;
                    while(zuo<you){
                        if(x[zh]-x[j]<=d){
                            zuo=zh;
                        }else{
                            you=zh-1;
                        }
                    }
                    if(x[zuo]-x[j]<=d and x[k]-x[zuo]<=d and x[zuo-1]-x[j]<=d and x[k]-x[zuo-1]<=d and x[k]-x[zuo-2]>d and zuo-1>j){
                        zong++;
                    }

                }
            }
        }
        cout<<zong<<endl;
    }

    }

    return 0;
}
