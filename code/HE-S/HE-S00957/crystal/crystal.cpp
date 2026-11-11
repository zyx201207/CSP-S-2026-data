#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,cnt,ans=1,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int k=1;
	while(m!=0){
		ll cnt=1;
		if(a[k-1]!=a[k]){
			a[k-1]++;
			m--;
			if(k-2>=0){
				if(a[k-2]!=a[k-1]){
					k--;
				}
			}
		}
		else{
			k++;
			for(int i=1;i<n;i++){
				if(a[i-1]==a[i])cnt++;
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans+1;
	return 0;
}
