#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],n,m,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		for(int j=0;j<m&&m-j+a[i-1]>=a[i]+j;j++){
			a[i]+=j;
			int l=i-1,cnt=m-j,num=1;
			while(cnt>=(a[i]-a[l])&&l>0){
				cnt-=(a[i]-a[l]);
				num++;
				l--;
			}
			ans=max(ans,num);
			a[i]-=j;
		}
	}
	cout<<ans;
	return 0;
}
