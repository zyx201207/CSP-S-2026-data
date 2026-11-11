#include<bits/stdc++.h>
using namespace std;
long long n,oi=0,ans,ax,x[200005];char y[200005];
bool mj=1;char hk;string S,P;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        int a;char b;cin>>a>>b;
        cout<<0;return 0;
    }
    cin>>x[1]>>y[1];hk=y[1];
    for(int i=2;i<=n;i++){
        cin>>x[i]>>y[i];ax+=x[i];
        if(mj){
            if(y[i]!=hk){mj=0;}
        }
    }ax+=x[1];
    if(mj){
        cout<<0;return 0;
    }bool lage=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x[i];j++){
            if(lage){
                S+=y[i];oi+=1;
                if(oi==ax/2){lage=0;}
            }else{
                P+=y[i];
            }//cout<<oi<<endl;
        }
    }
    int df=(ax%2==0?0:1);
    for(int i=0;i<ax/2;i++){
        if(S[ax/2-i]==P[i+df]){
            ans++;//cout<<"op"<<endl;
        }
    }
    cout<<ax/2-ans<<endl;
}
