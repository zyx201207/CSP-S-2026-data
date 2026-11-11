#include <bits/stdc++.h>
using namespace std;
long long n,mid,cnt,r,f,h,k;
long long a[200010];
char d[200010];
int main(){
    freopen("string.in","r",stdin);
    cin>>n;
    mid=0,f=n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>d[i];
        mid+=a[i];
    }if(mid%2==0){
        f=n-1;
    }for(int i=0;i<n-i-r;i++){
        if(d[i]!=d[n-i-r]){
            if(a[i]<a[n-i-r]){
                cnt+=a[i];
                a[n-i-r]=a[n-i-r]-a[i];
                r--;
            }
            else{
                cnt+=a[n-i-r];
                a[i]=a[i]-a[n-i-r];
                i--;

            }
        }else{
            if(a[i]<a[n-i-r]){
                a[n-i-r]=a[n-i-r]-a[i];
                r--;
            }
            else{
                a[i]=a[i]-a[n-i-r];
                i--;

            }
        }
        h=i,k=n-i-r;
    }
    if(mid%2==0||d[h+1]!=d[k-1]){
        cnt++;
    }
    cout<<cnt;
    freopen("string.out","w",stdout);
    return 0;
}