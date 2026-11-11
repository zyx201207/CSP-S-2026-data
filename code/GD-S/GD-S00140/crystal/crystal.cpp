#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],ans;
bool flag=1,flag1=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(flag && a[i]!=i){
			flag=0;
		}
	}
	if(flag){
		ans=1;
		for(int i=1;;i++){
			if(m>=i){
				m-=i;
				ans++;
			}else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag1=0;
			break;
		}
	}
	if(flag1){
		ll tmp=a[2]-a[1];
		ans=1;
		for(int i=tmp;;i+=tmp){
			if(m>=i){
				m-=i;
				ans++;
			}else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ll tmp=m;
		ll sum=1;
		for(int j=i-1;j>=1;j--){
			if(tmp>=a[i]-a[j]){
				tmp-=(a[i]-a[j]);
				sum++;
			}else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
