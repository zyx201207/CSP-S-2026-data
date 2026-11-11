#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000100];
int maxn;
int a1;
int a2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]&a[j]>maxn&&i!=j){
                    maxn=a[i]&a[j];
                    a1=a[i];
                    a2=a[j];
                }
            }
        }
    }else if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]&a[j]>maxn&&i!=j){
                    maxn=a[i]&a[j];
                    a1=a[i];
                    a2=a[j];
                }
            }
        }
        for(int i=1;i<=n;i++){
            maxn=max(maxn,maxn&a[i]);
        }
    }else if(m==n){
        for(int i=1;i<=n;i++){
            sort(a+1,a+n+1);
            maxn=a[1];
        }
    }else{
        for(int i=1;i<=n;i++){
            sort(a+1,a+n+1);
            maxn=a[m];
        }
    }
    cout<<maxn;
    return 0;
}

