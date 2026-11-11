#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
long long d;
long long sum;
bool check(long long a[]){
    d=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=d||d==0) return 0;
    }
    return 1;
}
int cut(int m){
    int i=1;
    int f=0;
    while(1){
        m=m-i*d;
       i++;
        if(m<0)  {f=i-1; break;}
        if(m==0) {f=i; break;}
    }
    return min(f,n-1);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(check(a)){
        cout<<1+cut(m);
        return 0;
    }
    int mid=0;
     mid=n/2+1;

for(int j=1;j<=n;j++){
    long long cnt=0,ans=0;
    bool f=1;
    for(int i=j;i>=1;i--){
        ans+=abs(a[j]-a[i]);
        cnt++;
        if(ans>m) {
            sum=max(sum,cnt-1);
            f=0;
            break;
        }
        else if(ans==m){
            sum=max(sum,cnt);
            f=0;
            break;
        }
    }
    if(f) sum=max(sum,cnt);
}
cout<<sum;
}