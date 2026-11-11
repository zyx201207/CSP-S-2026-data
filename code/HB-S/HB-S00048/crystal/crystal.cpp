#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long da[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        da[i]=abs(a[i]-a[i-1]);
    }
    int ans=0;
    for(int i=1;i<=n-1;i++){
        int num=2;
        while(i+num-1<=n){
            long long sum=0;
            for(int j=i;j<=i+num-1;j++){
                sum+=da[j];
            }
            if((sum<=m)&&(num>ans)){
                ans=num;
            }
        }
    }
    cout<<ans;
    return 0;
}
