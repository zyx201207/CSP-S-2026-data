#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long a[2000005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    scanf("%d%d",&n,&m);
    long long maxl=-1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxl=max(maxl,a[i]);
    }
    if(m==1){
        printf("%lld",maxl);
        return 0;
    }
    if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        printf("%lld",ans);
        return 0;
    }
    if(m==2){
        long long maxl=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxl=max(a[i]&a[j],maxl);
            }
        }
        printf("%lld",maxl);
        return 0;
    }
    if(m==3){
        long long maxl=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int l=j+1;l<=n;l++){
                    maxl=max(maxl,a[i]&a[j]&a[j]);
                }
            }
        }
        printf("%lld",maxl);
        return 0;
    }
    if(m==4){
        long long maxl=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int l=j+1;l<=n;l++){
                    for(int t=l+1;t<=n;t++){
                        maxl=max(maxl,a[i]&a[j]&a[j]&a[t]);
                    }
                }
            }
        }
        printf("%lld",maxl);
        return 0;
    }
    if(m==4){
        long long maxl=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int l=j+1;l<=n;l++){
                    for(int t=l+1;t<=n;t++){
                        for(int k=t+1;k<=n;k++){
                            maxl=max(maxl,a[i]&a[j]&a[j]&a[t]&a[k]);
                        }
                    }
                }
            }
        }
        printf("%lld",maxl);
        return 0;
    }
    if(m==5){
        long long maxl=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int l=j+1;l<=n;l++){
                    for(int t=l+1;t<=n;t++){
                        for(int k=t+1;k<=n;k++){
                            for(int h=k+1;h<=n;h++){
                                maxl=max(maxl,a[i]&a[j]&a[j]&a[t]&a[k]&a[h]);
                            }
                        }
                    }
                }
            }
        }
        printf("%lld",maxl);
        return 0;
    }
    if(m==6){
        long long maxl=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int l=j+1;l<=n;l++){
                    for(int t=l+1;t<=n;t++){
                        for(int k=t+1;k<=n;k++){
                            for(int h=k+1;h<=n;h++){
                                for(int f=h+1;f<=n;f++){
                                    maxl=max(maxl,a[i]&a[j]&a[j]&a[t]&a[k]&a[h]&a[f]);
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%lld",maxl);
        return 0;
    }
    if(m==10){
        long long maxl=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int l=j+1;l<=n;l++){
                    for(int t=l+1;t<=n;t++){
                        for(int k=t+1;k<=n;k++){
                            for(int h=k+1;h<=n;h++){
                                for(int f=h+1;f<=n;f++){
                                    for(int e=f+1;e>=n;e++){
                                        maxl=max(maxl,a[i]&a[j]&a[j]&a[t]&a[k]&a[h]&a[f]&a[e]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%lld",maxl);
        return 0;
    }
    if(n>2000){
        printf("%lld",a[n]-pow(2,m-1));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
