#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=1,cha,last;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==1){
        cout<<1;
        return 0;
    }
    long long r=1;
    for(int l=1;l<=n;l++){
        while(r+1<=n){
            last=cha;
            cha+=(r-l+1)*(a[r+1]-a[r]);
            if(cha>m){
                cha=last;
                break;
            }
            r++;
        }
        ans=max(ans,r-l+1);
        cha-=(a[r]-a[l]);
    }
    cout<<ans;
	return 0;
}

