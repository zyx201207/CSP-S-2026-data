#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[500005],k[500005],a[200005][501],t[200005][501];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j][i]>>t[j][i];
        }
    }
    for(long long i=1;i<=q;i++){
        long long x,y,alltime=0,xa[200005],ya[200005],passs=0,xa1,ya1;
        cin>>x>>y;
        for(long long j=1;j<=n;j++){
            for(int f=1;f<=k[j];f++){
                if(xa[f]==1&&ya[f]==1){
                    passs=1;
                }
            }
            if(passs==1){
                break;
            }
            for(int f=1;f<=n;f++){
                if(xa[f]==1){
                    xa1=f;
                }
                if(ya[f]==1){
                    ya1=f;
                }
            }
            for(long long f=1;f<=k[j];f++){
                if(a[f][j]==x){
                    alltime+=t[f][j]+w[x];
                    xa[j]=1;
                    break;
                }
            }
            for(long long f=1;f<=k[j];f++){
                if(a[f][j]==y){
                    alltime+=t[f][j]+w[y];
                    ya[j]=1;
                    break;
                }
            }
        }
        if(passs==0){
            for(long long f=1;f<=k[xa1];f++){
                for(long long j=1;j<=k[ya1];j++){
                    if(a[f][xa1]==a[j][ya1]){
                        alltime+=t[f][xa1]+t[j][ya1];
                    }
                }
            }
        }
        cout<<alltime<<endl;
    }

    return 0;
}
