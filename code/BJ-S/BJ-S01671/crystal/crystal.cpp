#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m,a[500010];
long long d[500010],s[500010];
int mx;
//sum(l,r)=s[r]-s[l-1]-(l-1)*(a[r]-a[l-1]);
long long sum(int l,int r){
    return s[r]-s[l-1]-(l-1ll)*(a[r]-a[l-1]);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++){
        s[i]=(i-1)*d[i]+s[i-1];
    }
    int i=1,j=1;
    while(i<=n){
        while(sum(i,j+1)<=m&&j<=n){
            j++;
        }
        int len=j-i+1;
        mx=max(mx,len);
        i++;
    }
    cout<<mx<<endl;
    return 0;
}
