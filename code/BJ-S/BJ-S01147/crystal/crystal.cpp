#include<bits/stdc++.h>
#define N 500005
using namespace std;
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    int a[N];
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=n;i>=1;i--){
        int cnt=0;
        for(int j=1;j<i;j++)
            cnt+=(a[i]-a[j]);
        if(cnt<=m&&ans<i)
			ans=i;
    }
    cout << ans;
}
