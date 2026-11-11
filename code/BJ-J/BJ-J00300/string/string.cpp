#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,a[N];
ll sum[N],cnt,l=1,r;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum[i]=sum[i-1]+a[i];
    }
    r=sum[n];
    int j=1,k=n;
    while(j<k){
        if(c[j]!=c[k]){
            cnt+=min(sum[j]-l+1,r-sum[k-1]);
        }
        if(sum[j]-l+1==r-sum[k-1]){
            l=sum[j]+1;
            r=sum[k-1];
            j++;
            k--;
        }else if(sum[j]-l<r-sum[k-1]){
            r-=sum[j]-l+1;
            l=sum[j]+1;
            j++;
        }else{
            l+=r-sum[k-1];
            r=sum[k-1];
            k--;
        }
        //cout<<j<<' '<<k<<' '<<l<<' '<<r<<' '<<cnt<<'\n';
    }
    cout<<cnt<<'\n';
    return 0;
}
