#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int> a(n+2);
    vector<int> cnt(m+2,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int ans1=0,ans2=0;
        for(int j=i;j<=n;j++){
            if(a[j]==1&&ans1==0)ans1++;
            else if(a[j]==2&&ans2==0)ans2++;
            else if(a[j]!=a[j-1]){
                if(a[j]==1)ans2=0;
                if(a[j]==2)ans1=0;
            }
        }
        cnt[1]+=ans1,cnt[2]+=ans2;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
