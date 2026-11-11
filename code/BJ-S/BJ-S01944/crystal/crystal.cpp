#include<bits/stdc++.h>
using namespace std;

long long a[1145140];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    long long nowcost=0;int ans=1,left=0;
    for(int i=1;i<n;i++){
        nowcost+=(i-left)*(a[i]-a[i-1]);
        while(nowcost>m){
            nowcost-=(a[i]-a[left]);
            left++;
        }
        ans=max(ans,i-left+1);
    }
    cout<<ans<<endl;
}

//大洋里没有值域最大点，到时候测一下，小心去年