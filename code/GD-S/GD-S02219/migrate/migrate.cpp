#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],x1[2000005],lj[2000005];
int sl(){
    int cnt=0;
    cin>>n>>d>>x[1];
    for(int i=2;i<=n;i++){
        cin>>x[i];
        x1[i]=x[i]-x[i-1];
    }
    //if(d==3||d==1) return cnt;
    for(int i=1;i<=n;i++){
        x[i]=0;
    }
    int len=0;
    for(int i=1;i<=n;i++){
        if(x1[i]<=d){
            len++;
        }
    }
    for(int i=2;i<=n;i++){
        x1[i]=x1[i-1]+x[i]-x[i-1];
    }
    lj[1]=0;
    lj[2]=1;
    for(int i=3;i<=len;i++){
        for(int j=1;j<=d;j++){
            //if(x1[i]-x1[i-j]<=d){
                //lj[i]++;
                //break;
            //}
            lj[i]+=lj[i-j];
        }
        for(int j=d+1;j<len;j++){
            //if(x1[i]-x1[i-j]<=d) break;
            lj[i]-=lj[i-j];
        }
    }
    for(int i=1;i<=len;i++){
        //for(int j=i-2;j>=1;j++) lj[i]-=lj[i-j];
        if(lj[i]==2) cnt++;
        //cout<<lj[i]<<' ';
        lj[i]=0;
    }
    return cnt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cout<<sl()<<endl;
    }
    return 0;
}
