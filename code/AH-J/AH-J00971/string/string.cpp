#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
long long a1[200005];
long long a2[200005];
char c1[200005];
char c2[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++){
            cin>>a[i]>>c[i];
        sum+=a[i];
    }
    long long as=0;
    int l=1;
    while(as<sum/2){
        if(as+a[l]>sum/2){
            a1[l]=sum/2-as;
            c1[l]=c[l];
        }else{
            a1[l]=a[l];
            c1[l]=c[l];
        }
        as+=a[l];
        l++;
    }
    as=0;
    int l1=n;
    while(as<sum/2){
        if(as+a[l1]>sum/2){
            a2[n-l1+1]=sum/2-as;
            c2[n-l1+1]=c[l1];
        }else{
            a2[n-l1+1]=a[l1];
            c2[n-l1+1]=c[l1];
        }
        as+=a[l1];
        l1--;
    }
    as=sum/2;
    l=1;
    l1=1;
    long long ans=0;
    while(as>0){
        if(c1[l]==c2[l1]){
            if(a1[l]<a2[l1]){
                as-=a1[l];
                a2[l1]-=a1[l];
                l++;
            }else if(a1[l]==a2[l1]){
                as-=a1[l];
                l++;
                l1++;
            }else{
                as-=a2[l1];
                a1[l]-=a2[l1];
                l1++;
            }
        }else if(a1[l]<a2[l1]){
            as-=a1[l];
            ans+=a1[l];
            a2[l1]-=a1[l];
            l++;
        }else if(a1[l]==a2[l1]){
            ans+=a2[l1];
            as-=a1[l];
            l++;
            l1++;
        }else{
            as-=a2[l1];
            ans+=a2[l1];
            a1[l]-=a2[l1];
            l1++;
        }
    }
    cout<<ans;
return 0;
}
