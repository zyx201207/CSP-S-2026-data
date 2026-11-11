#include<bits/stdc++.h>
using namespace std;

int a[200005];
int n,m,mx;

void dfs(int in,int sum,int mk){
    if(mk==m){
        mx=max(mx,sum);
        return ;
    }
    for(int i=in+1;i<=n;i++){
        dfs(i,sum&a[i],mk+1);
    }
}

bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        for(int i=1;i<=n;i++){
            dfs(i,a[i],1);
        }
        cout<<mx;
    }else if(n<=2000){
        sort(a+1,a+1+n);
        if(m==1){
            cout<<a[n];
        }
        if(m==n){
            int sum=a[1];
            for(int i=2;i<=n;i++){
                sum=sum&a[i];
            }
            cout<<sum;
        }
        if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    mx=max(a[i]&a[j],mx);
                }
            }
            cout<<mx;
        }
    }else{

        if(m==n-1){
            sort(a+1,a+1+n);
            int sum=a[1];
            for(int i=2;i<=n;i++){
                sum=sum&a[i];
            }
            for(int i=1;i<=n;i++){
                a[i]=-(~a[i])+1;
                mx=max(mx,sum&a[i]);
            }
            cout<<mx;
            return 0;
        }

        sort(a+1,a+1+n,cmp);
            int sum=a[1];
            for(int i=2;i<=m;i++){
                sum=sum&a[i];
            }
        cout<<sum;
    }

    return 0;
}
