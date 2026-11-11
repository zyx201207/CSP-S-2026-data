#include<bits/stdc++.h>
using namespace std;
long long n,m,okk,R,same,fl,bj;
int ook;
long long a[100005],da[100005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=1e9+5;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            okk++;
        }
    }
//    cout<<"okk"<<okk<<'\n';
    if(okk+1==n){
        cout<<n;
        return 0;
    }
    a[n+1]=1e9+5;
    a[n+2]=1e9+5;
    fl=3;
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            bj=i;
            ook=1;
        }
    }
//----------------------------------------------------
//ok
    if(ook==0){
        for(int i=1;i<=n;i++){
            sort(a,a+n);
            if(a[2]!=a[1]&&a[2]>a[1]){
                if(a[2]-a[1]<=m){
                    m-=(a[2]-a[1]);
                    a[1]=a[2];
                }
            }
            if(a[2]==a[fl]){
                fl++;
                if(m>=fl){
                    for(int j=1;j<=fl;j++){
                        a[j]++;
                    }
                    m-=fl;
                }else break;
            }else if(m>=fl-1){
                for(int j=1;j<=fl-1;j++){
                    a[j]++;
                }
                m-=(fl-1);
            }else break;
            if(m<=0) break;
        }
//---------------------------------------------------
//ok
    }else{
        for(int j=1;j<=n;j++){
            long long q,d,f1,f2;
            for(int i=bj;i<=n;i++){
                if(a[i]!=a[bj]){
                    f2=i;
                    break;
                }
             }
             for(int i=bj;i>=1;i--){
                if(a[i]!=a[bj]){
                    f1=i;
                    break;
                }
             }
             d=a[bj]-a[f1];
             q=a[f2]-a[bj];
             long long qq=f2-f1-1;
             if(q>d){
                if(m>=d){
                    m-=d;
                    a[f1]=a[bj];
                }else break;
             }else{
                 if(qq*q<d){
                    if(qq*q<=m){
                        m-=qq*q;
                        for(int j=f1+1;j<f2;j++){
                            a[j]+=q;
                        }
                    }else break;
                 }else if(d<=m){
                    m-=d;
                    a[f1]=a[bj];
                 }else break;
             }
             if(m<=0) break;
        }

    }
//------------------------------------
//ok
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            same=a[i];
            R+=2;
            a[i]=a[n+1];
            a[i+1]=a[n+1]+1;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==same){
            R++;
        }
    }
    cout<<R;
    return 0;
}
