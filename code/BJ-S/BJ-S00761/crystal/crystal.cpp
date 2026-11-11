#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],sum[500007],maxx;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n >>m;
    for(int i=1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = n;i >= 1;i--){
        for(int j = n;j>= 1;j--){
            if(a[j]>a[i]){
            }
            else if(a[j]==a[i]){
                sum[i]++;
            }
            else{
                if(m >= a[i]-a[j]){
                    m = m-a[i]+a[j];
                    sum[i]++;
                }
            }
        }
    }
    for(int i =1;i <= n;i++){
        maxx = max(sum[i]+1,sum[i+1]+1);
    }
    cout<<maxx;
}