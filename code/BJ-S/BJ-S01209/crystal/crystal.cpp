#include<bits/stdc++.h>
using namespace std;
long long int n,a[500005],cnt,ans;
unsigned long long m,sum,d;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        for(int i=1;i<=n;i++){
            sum=0,cnt=-1;
            for(int j=i-1;j>=1;j--){
                sum+=a[i]-a[j];
                if(sum>m){
                    cnt=i-j;
                    break;
                }
            }
            if(cnt==-1){
                cnt=i;
            }
            ans=max(cnt,ans);
        }
        cout<<ans;
    }else{
        sum=a[1],d=a[2]-a[1];
        for(int i=1;i<=n;i++){
            sum+=d*(i-1)+a[i];
            if(sum>m){
                ans=i-1;
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
