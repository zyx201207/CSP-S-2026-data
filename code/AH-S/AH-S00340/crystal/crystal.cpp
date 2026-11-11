#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,ans=1;
	ll m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	int i=1,j=1;
	for(;;){
		j++;
		if(i>n||j>n)break;
		if(b[j]==0){
			continue;
		}
		if(s>m){
			ans=max(ans,j-i-1);
			j--;
			s=s-a[j]+a[i];
			i++;
		//cout<<i<<' '<<j<<' '<<s<<' '<<ans<<'\n';
			continue;
		}
		else if(s==m){
			ans=max(ans,j-i);
			j--;
			s=s-a[j]+a[i];
			i++;
		//cout<<i<<' '<<j<<' '<<s<<' '<<ans<<'\n';
			continue;
		}
		s+=b[j]*(j-i);
		//cout<<i<<' '<<j<<' '<<s<<' '<<ans<<'\n';
	}
	if(s<=m)ans=max(ans,j-i);
	cout<<ans;
	return 0;
}
