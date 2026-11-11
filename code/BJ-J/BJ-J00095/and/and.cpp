#include<bits/stdc++.h>
using namespace std;
int a[200005][35],cnt,temp,maxc,t,tt[35],wt[35],ans;
long long m,n;
int cf(int y){
    int re=1;
    for(int i=1;i<=y;i++){
        re*=2;
    }
    return re;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=34;j++){
            a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cnt=0;
        cin>>temp;
        while(temp!=0){
            cnt++;
            if(temp%2==1){
                a[i][cnt]=1;
            }
            temp/=2;
        }
        a[i][0]=cnt;
        maxc=max(maxc,cnt);
    }
    t=maxc+1;
    while(t>1){
        t--;
        temp=0;
        for(int i=1;i<=n;i++){
            if(a[i][t]==1){
                temp++;
                wt[i]=1;
            }
            else{
                wt[i]=0;
            }
        }
        if(temp>=m){
            for(int i=1;i<=n;i++){
                if(wt[i]==1) continue;
                for(int j=1;j<=a[i][0]+1;j++){
                    a[i][j]=2;
                }
            }
            tt[t]=1;
        }
    }
    for(int i=1;i<=maxc;i++){
        if(tt[i]==1){
            ans+=cf(i-1);
        }
    }
    cout<<ans;
    return 0;
}
