//准考证号：GZ-S00420  学校：黔南布依族苗族自治州都匀第一中学  姓名：孙祖兴
#include<bits/stdc++.h>
using namespace std;

long long m,a[500010],tmp,n,l,r,ans;

bool cmp(long long x,long long y){
    return x<y;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,cmp);
    for(l=0;l<n;l++){
       if(l>0)tmp-=a[r]-a[l-1];
       while(tmp<=m&&r<n-1){
            r++;
            tmp+=(r-l)*(a[r]-a[r-1]);
       }
       while(tmp>m&&r>=l){
            tmp-=(r-l)*(a[r]-a[r-1]);
            r--;
       }
       ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
