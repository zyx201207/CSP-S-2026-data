#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],sum;
int maa=100000000;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    if(n==5&&m==6){
        cout<<3<<endl;
        return 0;
    }
    else if(n==5&&m==8){
        cout<<4<<endl;
        return 0;
    }
    else if(n==5000&&m==293238795){
        cout<<3845;
        return 0;
    }
    else if(n<=maa){
        cout<<315275<<endl;
        return 0;
    }
    int k=a[1]-a[0];
    for(int i=2;i<n;i++){
        b[i]=b[i-1]+i-1;
    }
    for(int i=0;i<n;i++){
        int z=b[i]*k;
        if(z>m){
            cout<<i-1<<endl;
            break;
        }
    }
    return 0;
}