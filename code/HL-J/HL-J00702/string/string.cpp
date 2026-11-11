#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long mo=0,n,t,i;
    cin>>n;
    t=n;
    long long a[n+1];
    char c[n+1];
    for(i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(i=1;;){
        if(i==t){
            break;
        }
        if(a[t]==0){
            t-=1;
        }
        if(a[i]==0){
            i+=1;
        }
        if(i==t+1){
            break;
        }
        if(c[i]!=c[t]){
            if(a[i]>=a[t]){
                mo+=a[t];
                a[i]-=a[t];
                a[t]=0;
            }
            else{
                mo+=a[i];
                a[t]-=a[i];
                a[i]=0;
            }
        }
        else{
            if(a[i]>=a[t]){
                a[i]-=a[t];
                a[t]=0;
            }
            else{
                a[t]-=a[i];
                a[i]=0;
            }
        }
    }
    cout<<mo;
    return 0;
}
