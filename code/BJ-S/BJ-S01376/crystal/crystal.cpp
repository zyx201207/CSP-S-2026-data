#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int ans=1;
long long sum=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1;
    int r=2;
    for(;r<=n;r++){
        int siz=r-l+1;
        long long cha=a[r]-a[r-1];
        while(sum+((siz-1)*cha)>m){
            siz--;
            sum-=(a[r-1]-a[l]);
            l++;
        }
        sum+=((siz-1)*cha);
        ans=max(ans,siz);
    }
    cout<<ans;
    return 0;
}
