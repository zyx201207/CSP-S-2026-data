#include<bits/stdc++.h>
using namespace std;
int a[200010],k[40];
void bk(int x){
    for(int i=30;i>=0;--i){
        if(x|(1<<i))++k[i];
    }return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out"."w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        bk(a[i]);
    }/*int ans=0;
    for(int i=1;i<=m;++i){
        int ma=-1;
        for(int i=1;i<=n;++i){
            if(a[i]>ma)ma=a[i];
        }ans|=ma;
        ma=(~ma);
        for(int i=1;i<=n;++i){
            a[i]&=ma;
        }
    }cout<<ans;*/
    sort(a+1,a+n+1);
    if(n<=20){
        int ma=-1;
        for(int i=1;i<=(1<<n);++i){
            if(builtin_popcount(i)==m){
                long long o=(1<<31)-1;
                for(int j=1;j<=n;++j){
                    if((1<<j)|i){
                        o&=a[j];
                    }
                }if(o>ma)ma=o;
            }
        }cout<<ma;
        return 0;
    }
    if(m==1){
        int ma=-1;
        for(int i=1;i<=n;++i){
            if(a[i]>ma)ma=a[i];
        }cout<<ma;
        return 0;
    }if(m==n){
        long long ma=(1<<31)-1;
        for(int i=1;i<=n;++i){
            ma&=a[i];
        }cout<<ma;
        return 0;
    }if(m<=2){
        int ma=-1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i!=j){
                    if(ma<a[i]&a[j]){
                        ma=a[i]&a[j];
                    }
                }
            }
        }cout<<ma;
        return 0;
    }
    if(a[n]<=(2<<10)){
        for(int i=a[n];i>0;--i){
            int o=0;
            for(int j=1;j<=n;++j){
                if((a[j]&i)==i)++o;
            }if(o>=m){
                cout<<i;
                return 0;
            }
        }cout<<0;
        return 0;
    }
    for(int i=30;i>=0;--i){
        if(k[i]>=m){
            cout<<(1<<i)-1;
            return 0;
        }
    }cout<<0;
    return 0;
}