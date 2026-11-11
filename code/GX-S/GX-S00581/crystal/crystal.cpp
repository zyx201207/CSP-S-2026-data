#include<bits/stdc++.h>
using namespace std;
int a[500009],b[500009];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,maxn=0,g=0,f=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    if(m==0){
        for(int i=1;i<=n;i++){
                int k=0;
            for(int j=1;j<=n;j++){
                if(a[i]==b[j]){
                    k++;
                }
            }
            if(k>=maxn)maxn=k;
        }
    }
    else{
        int h;
        for(int i=2;i<=n;i++){
                int g=0;
                h=b[i];
            for(int j=i-1;j>0;j--){
                while(m>=0){
                    m-=b[i]-b[j];
                    g++;
                }
            }
            if(g>maxn){
                maxn=g;
            }
            if(a[i]==h)f++;
        }
        //if(m%2==0){
            maxn=g+f;
        //}
        //else{
           maxn=g+f-1;
    }
    cout<<maxn;
        return 0;
}

