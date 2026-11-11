#include<bits/stdc++.h>
using namespace std;
int main(){
    
    freopen("crystal.in","r",stdin);
    freopen("cryspen.out","w",stdout);
    long long n,m,i,sum=1,x,y=0,f=0,c=0,d=0;
    cin>>n>>m;
    int a[n];
    for(i=0;i<=n;i++){
        cin>>a[i];
    }
    for(x=1;x<=n;x++){
        if(a[x]>=a[x-1]){
            a[x]=a[x];
        }
        else{
            y=a[x-1];
            a[x-1]=a[x];
            a[x]=a[y];
        }
          if(x=1){
              x=x-1;
          }
          else{
              x=x-2;
          }
    }
    if(i%2==0){
        x=a[i/2];
    }
    else{
        i=i/2;
        x=a[i+1];
    }
    for(int e=0;m>0;e++){
        for(i=0;i<=x;i++){
            d=c;
            c=x-a[i];
            if(d=0){
                y=c;
                continue;
        }
            if(d<c){
                y=d;
        }
    }
        if(m>x-y){
            f=x-y;
            m=m-f;
}   
        if(a[x]=f){
            break;
}
        sum++;
    }  
    cout<<sum;

    return 0;
}