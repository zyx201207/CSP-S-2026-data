#include<bits/stdc++.h>
using namespace std;
int main(){
    ("subway.in","r",stdin);
    ("subway.out","w",stdout);
    long long c,n,m,d,q,i,j,l;
    cin>>c>>n>>m>>d>>q;
    long long w[m];
    for(i=0;i<m;i++){
        cin>>w[i];
    }
    long long a[n][d],t[n][d];
    for(int i=0;i<n;i++){
        long long k;
        cin>>k;

        for(j=0;j<k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        long long x,y,tnt=0;
        vector<long long> platform,time;
        cin>>x>>y;
        tnt+=w[x]+w[y];
        long long ca;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                ca=t[i][x]+t[i][j];
                for(l=j+1;l<m;l++){
                    ca=min(ca,t[i][x]+t[i][l]);
                }
                for(l=j+1;l<m;l++){
                    if(t[i][l]==ca-t[i][x]){
                        time[i]=t[i][l];
                        platform[i]=a[i][l];
                    }
                }
            }
            long long b=time[i];
            for(j=i+1;j<m;j++){
                b=min(b,time[j]);
            }
            for(j=i+1;j<m;j++){
                if(b==time[j]){
                    tnt+=time[x];
                    tnt+=time[j];
                    x=platform[j];

                }
            }
        }
        cout<<tnt<<endl;
    }
    return 0;
}
