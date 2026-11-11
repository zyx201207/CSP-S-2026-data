#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m;
    int n;
    long long sum=0,cnt=0,ans=0;
    int a[100005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        cnt=1,sum=0;
        int l=1,r=1;
        for(int j=1;j<=n;j++){
            if(i-l>=0&&i+r<=n-1){
                if(a[i]-a[i-l]<=a[i+r]-a[i]){
                    sum+=(a[i]-a[i-l]);
                    l++;
                }
                else if(a[i]-a[i-l]>a[i+r]-a[i]){
                    sum+=(a[i+r]-a[i]);
                    r++;
                }
            }
            else if (i+r<=n-1){
                {
                sum+=(a[i+r]-a[i]);
                r++;
                }
            }
            else if(i-l>=0){
                sum+=(a[i]-a[i-l]);
                l++;
            }

            else
                break;
            if(sum>m){
                break;
            }
            if(sum==m){
                cnt++;
                break;
            }

            if(sum<m){
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
