#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;long long m,tmp=0;
    cin>>n>>m;
    int ans=0,ans2=0,l=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        tmp+=(i-l)*(a[i]-a[i-1]);
        ans2++;
        for(;l<i;){
            if(tmp<=m)break;
            tmp-=a[i]-a[l];
            ans2--;
            l++;
        }
        ans=max(ans,ans2);
    }
    cout<<ans;
    return 0; 
}
