#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,sum[200005],sum2[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        sum2[i]=sum[i+1]+a[i];
    }
    for(int i=1,j=n;a[i]!=0&&a[j]!=0;){
        if(c[i]!=c[j]){
            if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                a[j]=0;
                j--;
            }else if(a[i]<a[j]){
                ans+=a[i];
                a[j]-=a[i];
                a[i]=0;
                i++;
            }else{
                ans+=a[i];
                a[i]=0;
                a[j]=0;
                j--;
                i++;
            }
        }else{
            if(a[i]>a[j]){
                a[i]-=a[j];
                a[j]=0;
                j--;
            }else if(a[i]<a[j]){
                a[j]-=a[i];
                a[i]=0;
                i++;
            }else{
                a[i]=0;
                a[j]=0;
                j--;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
