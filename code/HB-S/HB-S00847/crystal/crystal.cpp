#include<bits/stdc++.h>
using namespace std;
long long a[600000],m,c[600000],mans,n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        c[i-1]=a[i]-a[i-1];
    }
    for(int i=2;i<n;i++){
        if(c[i]!=c[i-1]){
            long long sum;
            for(int ans=1;ans<=n;ans++){
                sum=0;
                for(int i=1;i+ans-1<=n;i++){
                    sum=0;
                    for(int j=i,cnt=1;j<=i+ans-2;j++,cnt++){
                        sum=sum+c[j]*cnt;
                    }
                    if(sum<=m){
                        mans=ans;
                    }
                }
            }
            cout<<mans;
            return 0;
        }
    }
    long long ans=0,anss=0;
    long long k=m/c[1];
    for(int i=1;i<=k;i++){
        ans+=i;
        anss++;
        if(ans>k){
            ans-=i;
            break;
        }
    }
    cout<<anss;
    return 0;
}
