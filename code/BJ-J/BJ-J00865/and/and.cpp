#include<bits/stdc++.h>
using namespace std;
struct T{
    bool t[35],k=1;
};
int x[35];
long long cf(int p){
    long long ans=1;
    for(int i=1;i<p;i++){
        ans*=2;
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=0;i<35;i++){
        x[i]=0;
    }
    int n,m;
    cin>>n>>m;
    T a[n];
    long long sum=0;
    int maxt=35;
    for(int i=0;i<n;i++){
        for(int j=0;j<35;j++){
            a[i].t[j]=false;
        }
    }
    for(int i=0;i<n;i++){
        long long lin;
        cin>>lin;
        int ti=34;
        for(;lin>0;ti--){
            a[i].t[ti]=lin%2;
            lin/=2;
        }
        maxt=min(maxt,ti);
    }
    for(int i=0;i<35;i++){
        for(int j=0;j<n;j++){
            x[i]+=a[j].t[i];
        }
    }
    for(int i=maxt+1;i<35;i++){
        if(x[i]>m){
            sum+=cf(35-i);
            for(int j=0;j<n;j++){
                if(a[j].t[i]!=1){
                    a[j].k=false;
                }
            }
        }
        else if(x[i]==m){
            sum+=cf(35-i);
            for(int j=0;j<n;j++){
                if(a[j].t[i]!=1){
                    a[j].k=false;
                }
            }
        }
        else{

        }
        for(int l=0;l<35;l++){
            x[l]=0;
        }
        for(int l=0;l<35;l++){
            for(int j=0;j<n;j++){
                if(a[j].k) x[l]+=a[j].t[l];
            }
        }
    }
    cout<<sum;
    return 0;
}
