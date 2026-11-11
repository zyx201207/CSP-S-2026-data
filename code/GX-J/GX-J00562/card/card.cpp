#include<bits/stdc++.h>
using namespace std;
bool mn(int k,int x,int y[10005],int m=0){
    while(x){
        int bn=1;
        if(k%10<y[bn]){
            k=k*10+y[bn];
        }
        else{
            k=0;
            k+=y[bn];

        }
        while(k){
            if(k%10==bn){
                m+=1;
            }
            k/=10;
        }
        bn++;
        x/10;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b,c[10005],su=0;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c[i];
        su+=c[i];
    }
    int n=0;
    for(int i=1;i<=a;i++){
        if(i>c[i]){
            continue;
        }
        cout<<mn(0,su,c,n)<<" ";
        n=0;
    }
    return 0;
}
