#include<bits/stdc++.h>
using namespace std;
int a[700000];
int to[40],tn[40][40],tw[400];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int si=1;
    for(int i=1;i<=30;i++){
        si*=2;
        to[i]=si;
    }
    to[0]=1;
    for(int j=1;j<=n;j++){
        cin>>a[j];
        //cout<<1<<"\n";
        int x1=a[j];
        for(int i=30;i>=0;i--){
            if(x1>=to[i]){
                tw[i]++;
                //ta[i][tw[i]]=a[j];
                x1-=to[i];
            }
        }
    }
    for(int i=30;i>=0;i--)tn[31][i]=tw[i];
    for(int i=30;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            for(int o=1;o<=n;o++){
                if((a[o]&(to[i]+to[j]))>=(to[i]+to[j]))tn[i][j]++;
            }
        }
    }
    //tn[1][0]=0;
    int ll=31,an=to[30],ty=0,ans=0;
    for(int i=30;i>=0;i--){
        //ty=an;
        //ans=0;
        ty=0;
        for(int j=1;j<=n;j++){
            if(ans==0&&((a[j]&to[i])>=to[i]))ty++;
            else if(ans!=0&&((a[j]&ans)>=ans))ty++;
        }
        //if(i==0)ty--;
        //cout<<ty<<"\n";
        if(ty>=m)ans+=to[i];
        else an=to[i-1];
    }
    cout<<ans;
    //cout<<1;
}
