#include<bits/stdc++.h>
using namespace std;
int n,m,a[2020],ans;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1,cmp);
        cout<<a[1];
    }
    if(m==2){
        int maxn=0,maxen=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxen=a[i]&a[j];
                if(maxen>maxn){
                    maxn=maxen;
                }
            }
        }
        cout<<maxn;
    }
    if(m==3){
        int maxn=0,maxen=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    maxen=a[i]&a[j]&a[k];
                    if(maxen>maxn){
                        maxn=maxen;
                    }
                }
            }
        }
        cout<<maxn;
    }
    return 0;
}
