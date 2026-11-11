#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long minx=1e15,maxx=-1e15;
    for(int i=1;i<=n;i++){
        cin>>a[i];minx=min(minx,a[i]);
        maxx=max(maxx,a[i]);
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=minx;i<=maxx+m;i++){
            long long sum=0,cnt=0;
            bool flag=false;
        for(int j=1;j<=n;j++){
            if(i>=a[j]){
                sum+=i-a[j];
                cnt++;
                if(sum>m){
                    ans=max(ans,cnt-1);
                    flag=true;
                    break;
                }
            }
        }
        if(!flag){
            ans=max(ans,cnt);
    }
        }
    cout<<ans;
return 0;
}
