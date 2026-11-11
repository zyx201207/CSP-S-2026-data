#include<bits/stdc++.h>
using namespace std;
int n,m;
long long s(int x){
    for(int i=1;i<=35;i++){
        if(pow(2,i)>=x+1){
            return i-1;
        }
    }
}
long long a[200100];
int z[200100][35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    if(m==1){
        cout << a[n];
    }
    if(m==2){
        long long mx=-1;
        for(long long i=n;i>=1;i--){
            for(long long j=i-1;j>=1;j--){
                mx=max((a[i]&a[j]),mx);
            }
        }
        cout << mx;
    }
    if(m==3){
        long long mx=-1;
        for(long long i=n;i>=1;i--){
            for(long long j=i-1;j>=1;j--){
                for(long long k=j-1;k>=1;k--){
                    mx=max((a[i]&a[j]&a[k]),mx);
                }
            }
        }
        cout << mx;
    }
    if(m==4){
        long long mx=-1;
        for(long long i=n;i>=1;i--){
            for(long long j=i-1;j>=1;j--){
                for(long long k=j-1;k>=1;k--){
                    for(long long l=k-1;l>=1;l--){
                        mx=max((a[i]&a[j]&a[k]&a[l]),mx);
                    }
                }
            }
        }
        cout << mx;
    }
    if(m==5){
        long long mx=-1;
        for(long long i=n;i>=1;i--){
            for(long long j=i-1;j>=1;j--){
                for(long long k=j-1;k>=1;k--){
                    for(long long l=k-1;l>=1;l--){
                        for(long long mm=l-1;mm>=1;mm--){
                            mx=max((a[i]&a[j]&a[k]&a[l]&a[mm]),mx);
                        }
                    }
                }
            }
        }
        cout << mx;
    }
    if(m==6){
        long long mx=-1;
        for(long long i=n;i>=1;i--){
            for(long long j=i-1;j>=1;j--){
                for(long long k=j-1;k>=1;k--){
                    for(long long l=k-1;l>=1;l--){
                        for(long long mm=l-1;mm>=1;mm--){
                            for(long long nn=mm-1;nn>=1;nn--){
                                mx=max((a[i]&a[j]&a[k]&a[l]&a[mm]&a[nn]),mx);
                            }
                        }
                    }
                }
            }
        }
        cout << mx;
    }
    return 0;
}
