#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e5+10;
ll n,m;
int a[MAXN];
int main(){
	

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	//int mx=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1,greater<int>());
	ll ans=a[1];
	int idx=1;
	while (m--){
		while((ans&a[idx])==0){
			idx++;
		}
		ans=ans&a[idx];
		//cout<<ans<<' ';
		//cout<<idx<<' '<<ans<< endl;
		idx++;
	}
	//	if(ans!=0)cout<<ans;
	//	else cout<<a[1];
	cout<<ans;
	//cout<<ans;
	//for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}
