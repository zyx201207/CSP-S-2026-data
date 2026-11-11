#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int ans=0,mm=m,nn=0,aa=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i){
            nn++;
        }
        int x=a[2]-a[1];
        if(i>=3){
            if(a[i]-a[i-1]==x){
                aa++;
            }
        }
    }
    if(nn==n){
        sort(a+1,a+n+1);
        int mid=0;
        if(n%2==0){
            mid=n/2+1;
        }
        else{
            mid=(n+1)/2;
        }
        for(int i=mid-1;i>=1 && mm>0;i--){
            mm-=1;
            ans++;
        }
        if(mm>0 && mid<=mm){
            while(mm>0){
                mm-=mid;
                mid++;
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    if(aa==n-1){
        sort(a+1,a+n+1);
        int mid=0,x=a[2]-a[1];
        if(n%2==0){
            mid=n/2+1;
        }
        else{
            mid=(n+1)/2;
        }
        for(int i=mid-1;i>=1 && mm>0;i--){
            mm-=x;
            ans++;
        }
        if(mm>0 && a[mid]<=mm){
            while(mm>0){
                mm-=mid*x;
                mid++;
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}