#include<bits/stdc++.h>
using namespace std;
int n,dz,dy,d1,d2;
long long ans;
struct zyd{
    int cd;
    char z;
}ly[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int a=1;a<=n;a++){
        cin>>ly[a].cd>>ly[a].z;
    }
    dz=1,dy=n,d1=ly[1].cd,d2=ly[n].cd;
    while(dz<dy){
        if(d1<d2){
            if(ly[dz].z!=ly[dy].z){
                ans+=d1;
            }
            d2-=d1;
            dz++;
            d1=ly[dz].cd;
        }else if(d1>d2){
            if(ly[dz].z!=ly[dy].z){
                ans+=d2;
            }
            d1-=d2;
            dy--;
            d2=ly[dy].cd;
        }else{
            if(ly[dz].z!=ly[dy].z){
                ans+=d2;
            }
            dz++;
            dy--;
            d1=ly[dz].cd;
            d2=ly[dy].cd;
        }
    }
    cout<<ans;
    return 0;
}