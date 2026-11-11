#include<bits/stdc++.h>
using namespace std;
int k[505][5005];
int a[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,z,l,h,num=0,t=0,y=100000001,u=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    //cout<<1;
    for(int i=1;i<=n;i++){
        cin>>z;
        for(int j=1;j<=z*2;j++){
            cin>>k[i][j];
        }
    }
    //cout<<1;
    for(int i=1;i<=q;i++){
        num=0;
        cin>>l>>h;
        //cout<<1;
        num+=a[l]+a[h];
        y=10000001;
        u=h;
        //cout<<1;
        while(t==0){
            for(int j=1;j<=n;j++){
                //cout<<j<<"cs"<<" ";
                //t=1;
                if(k[j][3]==h){
                    if(k[j][2]+k[j][4]<=y){
                        y=k[j][2]+k[j][4];
                        u=j;
                        //cout<<j<<"j";
                        //cout<<y<<"y";
                    }
                    if(k[j][1]==l){
                        //cout<<j<<"j";
                        num+=y;
                        cout<<num<<endl;
                        t=1;
                    }
                }
                if(k[j][1]==h){
                    if(k[j][2]+k[j][4]<=y){
                        //cout<<j<<"j";
                        y=k[j][2]+k[j][4];
                        u=j;
                        //cout<<y<<"y";
                    }
                    if(k[j][4]==l){
                        //cout<<j<<"j";
                        num+=y;
                        cout<<num<<endl;
                        t=1;
                    }
                }
            }
            num+=y;
            //cout<<"y";
            h=k[u][2];
        }

    }
    //cout<<k[6][3];
    return 0;
}
