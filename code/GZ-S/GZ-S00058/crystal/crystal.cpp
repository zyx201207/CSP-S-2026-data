//伍珈呈 GZ-S00058 北京师范大学贵阳附属中学
#include<bits/stdc++.h>
using namespace std;

long long a[500005];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int left=1,right=1;
    long long now=0;
    int maxn=-1;
    while(right<=n){
        // cout<<left<<" "<<right<<" "<<now<<'\n';
        // cout<<"maxn:"<<maxn<<"|dq:"<<right-left+1<<'\n';
        maxn=max(maxn,right-left+1);
        if(right==n){
            break;
        }
        right++;
        now+=(a[right]-a[right-1])*(right-left);
        while(now>m){
            now-=a[right]-a[left];
            left++;
        }
    }
    maxn=max(maxn,right-left+1);
    cout<<maxn<<'\n';
    return 0;
}