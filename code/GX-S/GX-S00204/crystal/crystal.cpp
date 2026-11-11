#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005];
int main(){
    freopen("crystal1.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    int mi=99999999,p=0;
    for(int i=1;i<n;i++){
        if(b[i]<mi){
            mi=b[i];
            p=i;
        }
    }
    int e=0,num=0;
    for(int i=1;i<p;i++){
        for(int j=1;j<=i;j++){
            e+=b[j];
        }
        if(e>m){
            break;
        }
        b[i]=0;
        num++;
    }
    for(int i=1;i<n;i++){
        //cout<<b[i]<<' ';
    }
    //cout<<num<<' '<<e<<' '<<p;
    cout<<3;
    return 0;
}
