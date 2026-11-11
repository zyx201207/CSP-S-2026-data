#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,max_=-100;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        sort(a+1,a+1+n);
        cout<<a[n];
    }else{
        if(m==n){
            ans=a[1];
            for(int i=2;i<=n;i++){
                ans=(ans|a[i]);
            }
            cout<<ans;
        }else{
            if(m==2){
                for(int i=1;i<=n;i++){
                    for(int j=i;j<=n;j++){
                        max_=max(max_,(a[i]|a[j]));
                    }
                }
                cout<<max_;
            }else{
                sort(a+1,a+1+n);
                cout<<a[n-m+1];
            }
        }
    }
    return 0;
}
