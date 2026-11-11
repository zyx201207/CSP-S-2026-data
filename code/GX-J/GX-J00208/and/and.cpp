#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10000001];
int n,m;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	if(m==1)cout<<a[n];
	else{
		if(m==2){
			int ans=LLONG_MIN;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					int tmp=a[i]&a[j];
					if(tmp>ans)ans=tmp;
				}
			}
			cout<<ans;
		}
		else if(m==n){
			int ans=a[1];
			for(int i=1;i<=n;i++){
				ans&=a[i];
			}
			cout<<ans;
		}
	}
    return 0;
}
