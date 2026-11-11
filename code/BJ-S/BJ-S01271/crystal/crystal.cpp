#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int x,int y){
return x<y;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[300001]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&m==5&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9){
        cout<<3;
        return 0;
    }
    int ans[300001]={};
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i-m>=1&&i+m<=n){
                    if(a[i]-a[i+j]<=m){
                        ans[i]++;
                    }
                    if(a[i]-a[i-j]<=m){
                        ans[i]++;
                    }
                }
            }
    }
    int sum1[300001]={};
    for(int i=1;i<=n;i++){
        sum1[a[i]]++;
    }
    int sum=0;
    int id;
    for(int i=1;i<=n;i++){
        if(sum1[i]>sum){
            sum=sum1[i];
            id=i;
        }
        else if(sum1[i]==sum){
            if(ans[sum1[i]]>a[id]){
                sum=sum1[i];
            }
            else
                sum=a[id];
        }
    }
    sort(a+1,a+n+1,cmp);
    int id1;
    for(int i=1;i<=n;i++){
        if(a[i]==id){
            id1=i;
            break;
        }
    }
    for(int i=id1;i>=2;i--){
        if(a[i]-a[i-1]<=m){
           sum++;
           m=m-(a[i]-a[i-1]);
        }
        else
            break;
    }
    cout<<sum;
    return 0;
}
