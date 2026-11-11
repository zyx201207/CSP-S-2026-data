#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,d[500005],a[500005],ans=1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    sort(d,d+n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i]=d[i];
        }
        int c=m,cnt=0;
        for(int j=i;j>=0;j--){
            if(c>=(a[i]-a[j])){
                c-=(a[i]-a[j]);
                a[j]=a[i];
            }else{
                break;
            }
        }
        int b=a[0];
        for(int j=0;j<=i;j++){
            if(b==a[j]){
                cnt++;
            }
            b=a[j];
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
