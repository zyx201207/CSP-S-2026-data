#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
long long m,min1=90000009,min2;
long long ans=1;
long long a[500005]={0};
int flag=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]!=i){
            flag=1;
        }
    }
    sort(a+1,a+1+n);
    if(flag=0){
            cout<<1<<endl;
        for(int i=n/2+(m+n%2)/n-1;i>=1;i--){
            if(a[n/2+(m+n%2)/n]-a[i]<=m){
                m-=a[n/2+(m+n%2)/n]-a[i];
                ans++;
            }else{
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    sum+=m;
    sum/=n;

    for(int i=1;i<=n;i++){
        if(abs(sum-a[i])<=min1){
            min1=abs(sum-a[i]);
            min2=i;
        }
    }
    for(int i=min2-1;i>=1;i--){
        if(a[min2]-a[i]<=m){
            m-=a[min2]-a[i];
            ans++;
        }else{
            break;
        }
    }
    cout<<ans;
    return 0;
}
