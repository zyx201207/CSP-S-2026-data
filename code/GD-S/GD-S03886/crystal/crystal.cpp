#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+7;
int n;
ll m,a[N],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	ll cnt=0;
	int l=1;
	for(int r=2;r<=n;r++){
		cnt+=(r-l)*(a[r]-a[r-1]);
		while(cnt>m&&l<=r){
			cnt-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1ll);
	}
	cout<<ans;
	return 0;
}
