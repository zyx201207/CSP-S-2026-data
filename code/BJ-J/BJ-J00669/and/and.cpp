#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N],maxx=-2e9;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //ans[1]=1;
  //  fmax(1);
   if(m==1){
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                long long xx=a[i]&a[j];
                maxx=max(maxx,xx);
            }
        }
    }else if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int x=j;x<=n;x++){
                    long long xx=a[i]&a[j]&a[x];
                    maxx=max(maxx,xx);
                }
            }
        }
    }else if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int x=j;x<=n;x++){
                    for(int y=x;y<=n;y++){
                        long long xx=a[i]&a[j]&a[x]&a[y];
                        maxx=max(maxx,xx);
                    }
                }
            }
        }
    }else if(m==5){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int x=j;x<=n;x++){
                    for(int y=x;y<=n;y++){
                        for(int z=y;z<=n;z++){
                            long long xx=a[i]&a[j]&a[x]&a[y]&a[z];
                            maxx=max(maxx,xx);
                        }
                    }
                }
            }
        }
    }else if(m==6){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int x=j;x<=n;x++){
                    for(int y=x;y<=n;y++){
                        for(int z=y;z<=n;z++){
                            for(int p=z;p<=n;p++){
                                long long xx=a[i]&a[j]&a[x]&a[y]&a[z]&a[p];
                                maxx=max(maxx,xx);
                            }
                        }
                    }
                }
            }
        }
    }else if(m==7){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int x=j;x<=n;x++){
                    for(int y=x;y<=n;y++){
                        for(int z=y;z<=n;z++){
                            for(int p=z;p<=n;p++){
                                for(int q=p;q<=n;q++){
                                    long long xx=a[i]&a[j];
                                    maxx=max(maxx,xx);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<maxx;
    return 0;
}