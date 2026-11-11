#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],m,c[N],cnt;
int n,res=1,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)c[i]=a[i]-a[i-1];
	ll s=0;
	int l=1;
	for(int i=2;i<=n;i++){
		s+=c[i];
		cnt+=c[i]*(i-l);
		while(cnt>m){
			cnt-=s;
			s-=c[l+1];
			l++;
		}
		ans=max(ans,i-l+1);
//		cout<<s<<' '<<cnt<<'\n';
	}
	cout<<ans;
	return 0;
}
