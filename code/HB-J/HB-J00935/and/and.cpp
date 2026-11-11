#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long t,sum=0;
    cin>>n>>m;
    if(m==n){
        for(int i=1;i<=n;i++){
            cin>>t;
            sum=sum&t;
        }
        cout<<sum;
        return 0;
    }
    else if( m==1){
        for(int i=1;i<=n;i++){
            cin>>t;
            sum=max(sum,t);
        }
        cout<<sum;
        return 0;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum=max(sum,a[i]&a[j]);
            }
        }
        cout<<sum;
        return 0;
    }
    else if(m==3){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    sum=max(sum,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<sum;
        return 0;
    }else if(m==4){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        sum=max(sum,a[i]&a[j]&a[k]&a[l]);
                    }

                }
            }
        }
        cout<<sum;
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum=max(sum,a[i]&a[j]);
            }
        }
        cout<<sum;
        return 0;
    }

    return 0;
}
