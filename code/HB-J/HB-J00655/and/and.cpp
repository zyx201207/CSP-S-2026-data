#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],k[200001][31],maxt=-1,cnt,ans;
bool bk[200001],b;
int pf(int x){
    int y=1;
    for(int i=1;i<=x;i++)y*=2;
    return y;
}
int main(){
    freopen(and.in,"r",stdin);
    freopen(and.out,"w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int x=a[i],t;
        for(t=0;t<=30;t++){
            if(pf(t)>x)break;
        }
        t--;
        maxt=max(maxt,t);
        while(t>=0){
            k[i][t]=x%2;
            x/=2;
            t--;
        }
    }
    b=0;
    for(int i=maxt;i>=0;i--){
        cnt=0;
        for(int j=1;j<=n;j++){
            if(k[j][i]==1){
                if(bk[j]==1||b==0){
                    cnt++;
                    bk[j]=1;
                }
            }
        }
        if(cnt>=m){
            ans+=pf(i);
            b=1;
        }
        else if(b==0){
            memset(bk,0,sizeof(bk));
        }
    }
    cout<<ans;
    return 0;
}
