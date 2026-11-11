#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,ans,t,p;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    //cout<<n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    for(int i=1,j=n;i<=j&&t<=sum/2&&p<=sum/2;){
        if(c[i]!=c[j]){
            ans+=min(a[i],a[j]);
        }
        t+=min(a[i],a[j]);
        p+=min(a[i],a[j]);
        if(a[i]>a[j]){
            a[i]-=a[j];
            j--;
        }
        else if(a[i]<a[j]){
            a[j]-=a[i];
            i++;
        }
        else{
            j--;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
