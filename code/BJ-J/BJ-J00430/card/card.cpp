#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    long long a[n+10],ans[n+10],x=0,y=0,r,t;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        r=a[1];
        if(a[i]!=r)t=a[i];
    }
    if(m==1){
        int rrr=0;
        while(n>0){
            rrr+=n%2;
            n--;
        }
        cout<<rrr;
        return 0;
    }
    for(int i=1;i<=n;i++){
        a[i-1]=0;
        x=0,y=0;
        int l=0;
        for(int j=1;j<=n;j++){
            if(a[j]==r)x++;
            if(a[j]==t)y++;
            if(x==2){
                l=j+1;
                x=0,y=0;
            }
            if(y==2){
                l=j+1;
                x=0,y=0;
            }
        }
        for(int i=l;i<=n;i++){
            if(x>0)ans[1]++;
            if(y>0)ans[2]++;

        }
    }
    for(int i=1;i<=2;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}