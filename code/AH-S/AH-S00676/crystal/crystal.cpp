#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,ans;
long long m;
long long a[N];
void read(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
}
void work(){
    int l=1;
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=(i-l)*(a[i]-a[i-1]);
        if(sum>m){
            while(sum>m)l++,sum-=a[i]-a[l-1];
        }
        /*while(k&&now>=1){
            if(a[i]-a[now]>=0&&a[i]-a[now]<=k)k-=a[i]-a[now],an++;
            now--;
        }*/

        ans=max(i-l+1,ans);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read();
    work();
    cout<<ans;
    return 0;
}
