#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,maxx,h,sum;
void f(int k,int c,int z){
    if(k>n)return ;
    if(c==m){
        sum=max(sum,z);
        return;
    }
    f(k+1,c,z);
    if(c==0){
        f(k+1,c+1,a[k]);
    }
    else f(k+1,c+1,a[k]&z);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    else if(m==n){
        h=a[1];
        for(int i=2;i<=n;i++)h=h&a[i];
        cout<<h;
        return 0;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum=max(sum,a[i]&a[j]);
           }
        }
        cout<<sum;
        return 0;
    }
    else {
        sort(a+1,a+n+1);
        sum=a[n];
        for(int i=n-1;i>n-m;i--){
            sum=(sum&a[i]);
        }
        cout<<sum;
        return 0;
    }
    return 0;
}

