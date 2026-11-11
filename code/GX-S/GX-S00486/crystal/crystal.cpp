#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50000005],k,ans,sum,J,f1,f2;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==i){
            f1++;
        }
        if(a[2]-a[1]==a[i]-a[i-1]){
            f2++;
        }
    }
    if(f1==n){
        while(m>=ans){
            J++;
            ans+=J;
        }
        cout<<min(J,n);
    }else if(f2==n-1){
        while(m>=ans){
            J++;
            ans+=J*(a[2]-a[1]);
        }
        cout<<min(J,n);
    }else{
    sort(begin(a),a+n+1);
    for(int i=n;i>=1;i--){
            k=m;
        if(i>1)
        for(int j=i-1;j>=1;j--){
            if((a[i]-a[j])<=k){
                J=j;
                k-=(a[i]-a[j]);
            }else{
                break;
            }
        }
        sum=max(sum,i-J+1);
    }
    cout<<sum;
    }
    return 0;
}
