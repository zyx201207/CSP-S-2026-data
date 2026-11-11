#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum[200005];
int sum2[200005];
int a[200005];
int def(int o){
    int l=0;
    while(o){
        o&=o-1;
        l++;
    }
    return l;
}
struct node{
    int v;
    int id;
};
bool cmp(node x,node y){
    if(x.v!=y.v){
        return x.v>y.v;
    }
    return a[x.id]>a[y.id];
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n,greater<int>());
        cout<<a[0];
        return 0;
    }
    if(m==2){
        long long mx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(a[i]&a[j]>mx){
                    mx=a[i]&a[j];
                }
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==n){
        long long u=a[0];
        for(int i=1;i<n;i++){
            u&=a[i];
        }
        cout<<u;
        return 0;
    }
    if(m==n-1){
        long long mx=-1;
        sum[0]=a[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]&a[i];
        }
        sum2[0]=a[n-1];
        for(int i=1;i<n;i++){
            sum2[i]=sum2[i-1]&a[n-i];
        }
        for(int i=0;i<n;i++){
            if(i==0){
                if(mx<sum2[n-i-1]){
                    mx=sum2[n-i-1];
                }
            }
            if(mx<sum[i-1]&sum2[n-i-1]){
                mx=sum[i-1]&sum2[n-i-1];
            }
        }
        cout<<mx;
        return 0;
    }
    bool flag=true;
    for(int i=0;i<n;i++){
        bool flag2=false;
        for(int j=0;j<30;j++){
            if(a[i]==pow(2,j)){
                flag2=true;
            }
        }
        if(!flag2){
            flag=false;
            break;
        }
    }
    if(flag){
        sort(a,a+n,greater<int>());
        cout<<a[m-1];
        return 0;
    }
    node p[500005];
    for(int i=0;i<n;i++){
        p[i].v=def(a[i]);
        p[i].id=i;
    }
    sort(p,p+n,cmp);
    int y=a[p[0].id];
    for(int i=1;i<m;i++){
        y&=a[p[i].id];
    }
    cout<<y;
    return 0;
}
