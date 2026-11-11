#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        long long sum=a[1];
        for(int i=2;i<=n;i++){
            sum=sum&a[i];
        }
        cout<<sum;
        return 0;
    }
    if(m==2){
        long long sum=-1;
        for(int i=1;i<=n;i++){
            long long sum1=a[i];
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                sum1=a[i]&a[j];
                sum=max(sum,sum1);
            }
        }
        cout<<sum;
        return 0;
    }
    if(m==3){
        long long sum=-1;
        for(int i=1;i<=n;i++){
            long long sum1=a[i];
            for(int x=1;x<=n;x++){
                    if(x==i)continue;
                for(int j=1;j<=n;j++){
                    if(j==i||j==x)continue;
                    sum1=sum1&a[j]&a[x];
                    sum=max(sum,sum1);
                }
            }
        }
        cout<<sum;
        return 0;
    }
    if(m==4){
        long long sum=-1;
        for(int i=1;i<=n;i++){
            long long sum1=a[i];
            for(int x=1;x<=n;x++){
                    if(x==i)continue;
                    for(int o=1;o<=n;o++){
                            if(o==i||o==x)continue;
                        for(int j=1;j<=n;j++){
                        if(j==i||j==x||j==o)continue;
                        sum1=sum1&a[j]&a[x]&a[o];
                        sum=max(sum,sum1);
                    }
                    }

            }
        }
        cout<<sum;
        return 0;
    }
    if(m==5){
        long long sum=-1;
        for(int i=1;i<=n;i++){
            long long sum1=a[i];
            for(int x=1;x<=n;x++){
                    if(x==i)continue;
                    for(int o=1;o<=n;o++){
                            if(o==i||o==x)continue;
                            for(int d=1;d<=n;d++){
                                if(d==i||d==x||d==o)continue;
                                for(int j=1;j<=n;j++){
                        if(j==i||j==x||j==o||j==d)continue;
                        sum1=sum1&a[j]&a[x]&a[o]&a[d];
                        sum=max(sum,sum1);
                    }
                            }

                    }

            }
        }
        cout<<sum;
        return 0;
    }
    if(m==1){
        long long sum=-1;
        for(int i=1;i<=n;i++){
            sum=max(sum,a[i]);
        }
        cout<<sum;
        return 0;
    }
    long long sum=-1;
    for(int i=2;i<=n;i++){
        long long sum1=a[1];
        for(int j=2;j<=n;j++){
            if(j==i)continue;
            sum1&=a[j];
        }
        sum=max(sum1,sum);
    }
    long long d=a[2];
    for(int i=3;i<=n;i++){
        d&=a[i];
    }
    cout<<max(sum,d);
    return 0;
}
