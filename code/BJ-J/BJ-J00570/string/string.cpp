#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010],sum,l[200010],r[200010],idx,idx1,idx2,A[200010],ans;
char ch[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
        l[i]=sum;
        sum+=a[i];
        r[i]=sum;
    }
    if(sum%2==0){
        int mid1=(sum>>1);
        int mid2=(sum>>1)+1;
        for(int i=1;i<=n;i++){
            if(l[i]>=mid1&&mid1<=r[i]){
                idx1=i;
            }
            if(l[i]>=mid2&&mid2<=r[i]){
                idx2=i;
            }
        }
        if(idx1!=idx2){
            ans+=1;
        }
        for(int i=idx2+1;i<=n;i++){
            A[i-idx2]=a[i];
        }
        for(int i=1;i<=idx1-1;i++){
            if(A[i]!=a[i]){
                ans++;
            }
        }
        cout<<ans;
    }
    else{
        int mid=(sum>>1)+1;
        for(int i=1;i<=n;i++){
            if(l[i]>=mid&&mid<=r[i]){
                idx=i;
            }
        }
        for(int i=idx+1;i<=n;i++){
            A[i-idx2]=a[i];
        }
        for(int i=1;i<=idx-1;i++){
            if(A[i]!=a[i]){
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
