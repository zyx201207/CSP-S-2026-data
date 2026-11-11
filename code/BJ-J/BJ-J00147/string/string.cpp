#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long he[200005];
long long ta[200005];
char hc[200005];
char tc[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sum,sum1,sum2,ans=0;
    sum=0;
    for (int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    int p,q;
    sum1=0;
    for (int i=0;i<n;i++){
        sum1+=a[i];
        if (sum1>=sum/2){
                he[i]=a[i]-sum1+sum/2;
                hc[i]=c[i];
                i=n;
        }
        else {
            he[i]=a[i];
            hc[i]=c[i];
        }
    }
    sum1=0;
    for (int i=n-1;i>=0;i--){
        sum1+=a[i];
        //cout<<i;
        if (sum1>=sum/2){
                ta[n-1-i]=a[i]-sum1+sum/2;
                tc[n-1-i]=c[i];
                i=-1;
        }
        else {
            ta[n-1-i]=a[i];
            tc[n-1-i]=c[i];
        }
    }
    //cout<<endl;
    sum1=0;
    sum2=0;
    p=0;
    q=0;
    //for (int i=0;i<n;i++){
      //  cout<<he[i]<<hc[i]<<ta[i]<<tc[i]<<endl;
    //}
    while (sum1<sum/2 or sum2<sum/2){
            //cout<<p<<q<<he[p]<<ta[q]<<endl;
        if (he[p]>ta[q]){
            if (hc[p]!=tc[q]){
                ans+=ta[q];
            }
            sum1+=ta[q];
            sum2+=ta[q];
            he[p]-=ta[q];
            q++;

        }
        else if (he[p]<ta[q]){
            if (hc[p]!=tc[q]){
                ans+=he[p];
            }
            sum1+=he[p];
            sum2+=he[p];
            ta[q]-=he[p];
            p++;

        }
        else {
            if (hc[p]!=tc[q]){
                ans+=he[p];
            }
            sum1+=he[p];
            sum2+=ta[q];
            p++;
            q++;
        }
    }
    cout<<ans;
    return 0;
}
