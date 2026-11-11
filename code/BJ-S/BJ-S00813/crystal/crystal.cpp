#include<bits/stdc++.h>//O(n^2)
using namespace std;
long long n,m,cry[1000000],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>cry[i];
    sort(cry,cry+n);
    for(int i=0;i<n;i++){
        long long cnt=0,j;
        for(j=i;j<=n;j++){
            if(cnt+(j-i)*(cry[j]-cry[j-1])>m)break;
            cnt+=(j-i)*(cry[j]-cry[j-1]);
        }
        ans=max(ans,j-i);
    }
    cout<<ans;
}