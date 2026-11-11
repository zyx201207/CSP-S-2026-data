#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[10000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int maxn=-1;
        for(int i=1;i<=n;i++){
            if(a[i]>maxn){
                maxn=a[i];
            }
        }
        cout<<maxn;
        return 0;

    }
    if(m==2){
            int maxn=-1;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                int b=a[i]&a[j];
                if(b>maxn){
                    maxn=b;
                }
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==3){
        int maxn=-1;
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                    int b=a[i]&a[j]&a[k];
                if(b>maxn){
                    maxn=b;
                }
                }

            }
        }
        cout<<maxn;
        return 0;
    }
    if(n==m){
        int b=a[1];
        for(int i=2;i<=n;i++){
            b=b&a[i];
        }
        cout<<b;
        return 0;
    }
    if(n==m-1){
        for(int j=1;j<=n;j++){
            if(j==1){
                int b=a[2];
                for(int i=3;i<=n;i++){
            if(i==j){
                continue;
            }
            b=b&a[i];
            }
            }else{
                int b=a[1];
            for(int i=2;i<=n;i++){
            if(i==j){
                continue;
            }
            b=b&a[i];
            }
            }
        }

        cout<<b;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
