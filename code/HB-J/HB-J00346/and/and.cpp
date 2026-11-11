#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n;
int a[200010];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int max1=INT_MIN;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>max1){
            max1=a[i];
        }
    }
    if(m==1){
        cout<<max1;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        int max2=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int ans=a[i]&a[j];
                if(ans>max2){
                    max2=ans;
                }
            }
        }
        cout<<max2;
        return 0;
    }
    if(m==n-1){
        int max3=INT_MIN;
        int num=a[2];
        for(int i=2;i<=n;i++){
            int ans=a[1];
            if(i!=2){
                num&=a[i];
            }
            for(int j=1;j<=n;j++){
                if(j==i){
                    continue;
                }
                ans&=a[j];
            }
            if(ans>max3){
                max3=ans;
            }
        }
        cout<<max(max3,num);
        return 0;
    }
    cout<<max1;
    return 0;
}
