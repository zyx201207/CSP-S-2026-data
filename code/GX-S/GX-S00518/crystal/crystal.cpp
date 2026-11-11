#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500001],f;
    cin>>n;
    cin>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
        f+=a[i];
    }
    f=(f+n)/n;
    for(int i=0;i<=n;i++){
        if(a[i]<f){a[i]=f-a[i];}
        else{a[i]=a[i]-f;}
    }
    sort(a,a+n-1);
    int i=0,jg=0;
    while(m>=0){
        if(a[i]==a[i+1]){
            jg+=1;
            i+=1;
        }else{
            a[i+1]-=1;
            m-=1;
        }
    }
    cout<<jg+1;

    return 0;
}

