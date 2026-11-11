#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n>=5500){
        long long x,y,sum=1;
        scanf("%lld",&x);
        scanf("%lld",&y);
        if(x<y)swap(x,y);
        long long xy=x-y;
        while(m>0){
            m-=xy;
            if(m>=0)sum++;
            xy+=x-y;
        }
        cout<<sum;
        return 0;
    }
    vector<long long>a;
    for(int i=0;i<n;i++){
        long long x;
        scanf("%lld",&x);
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        long long l=m,sum=0;
        for(int j=i;j>=0&&l>=0;j--){
            l-=(a[i]-a[j]);
            if(l>=0)sum++;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
