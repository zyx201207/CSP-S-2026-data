#include <bits/stdc++.h>
using namespace std;
int n,a[200001],m;
int s[100001];
int xx[1001],yy[1001],zz[1001];
int _and(int x,int y,int z){
    memset(xx,-1,sizeof(xx));
    memset(yy,-1,sizeof(yy));
    memset(yy,-1,sizeof(yy));
    int k=1,_max=-1;
    while (x/2!=0){
        xx[k]=x%2;
        x/=2;
        k++;
    }
    _max=max(_max,k-1);
    k=1;
    while (y/2!=0){
        yy[k]=y%2;
        y/=2;
        k++;
    }
    _max=max(_max,k-1);
    k=1;
    while (z/2!=0){
        zz[k]=z%2;
        z/=2;
        k++;
    }
    _max=max(_max,k-1);
    int sum=0;
    for (int i=1;i<=_max;i++){
        if (xx[i]==yy[i] && yy[i]==zz[i]){
            sum+=pow(2,i-1);
        }
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=-1;
    if (m==2){
        for (int i=1;i<n;i++){
            for (int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&=a[j]);
            }
        }
    }
    if (m==3){
        for (int i=1;i<n-1;i++){
            for (int j=i+1;j<n;j++){
                for (int k=j+1;k<=n;k++){
                    ans=max(ans,_and(a[i],a[j],a[k]));
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
