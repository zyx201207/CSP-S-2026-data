#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[200005],ans;
int pow(int y,int u){
    int yu=1;
    for(int i=1;i<=u;i++)yu*=y;
    return yu;
}
int ewq(int a,int b){
    int ans=0,i=1;
    while(1){
        ans+=((a%2==1)&&(b%2==1))*(pow(2,i)/2);
        if(a==1&&b==1)return ans;
        if(a==0||b==0)return ans;
        a/=2,b/=2;
        i++;
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(m==1){
        ans=a[n];
    }
    if(m==2){
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,ewq(a[i],a[j]));
            }
        }
    }
    if(m==3){
        for(int i=1;i<=n-2;i++)
        for(int j=i+1;j<=n-1;j++)
        for(int k=j+1;k<=n;k++)
        ans=max(ans,ewq(ewq(a[i],a[j]),a[k]));
    }
    if(m==4){
        for(int i=1;i<=n-3;i++)
        for(int j=i+1;j<=n-2;j++)
        for(int k=j+1;k<=n-1;k++)
        for(int i1=k+1;i1<=n;i1++)
        ans=max(ans,ewq(ewq(ewq(a[i],a[j]),a[k]),a[i1]));
    }
    if(m==5){
        for(int i=1;i<=n-4;i++)
        for(int j=i+1;j<=n-3;j++)
        for(int k=j+1;k<=n-2;k++)
        for(int i1=k+1;i1<=n-1;i1++)
        for(int i2=i1+1;i2<=n;i2++)
        ans=max(ans,ewq(ewq(ewq(ewq(a[i],a[j]),a[k]),a[i1]),a[i2]));
    }
    cout<<ans;
    return 0;
}