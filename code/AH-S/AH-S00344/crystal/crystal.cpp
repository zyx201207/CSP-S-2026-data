#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,ans;
ll a[N],cnt,sum,m,l=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        m-=(a[i]-a[i-1])*cnt;
        cnt++;
        while(cnt>0&&m<0){
            cnt--;
            l++;
            m+=a[i]-a[l];
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
