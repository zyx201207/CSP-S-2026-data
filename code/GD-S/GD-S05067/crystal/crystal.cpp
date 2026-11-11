#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e8+5;
ll n,m,num=0,sum=0,ans=0;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		sum=0;
		if(a[i]==a[i-1]) continue;
		for(int j=0;j<i;j++){
			sum+=a[i]-a[j];
		}
		if(sum>m) break;
		num=i+1;
		for(int j=i+1;j<n;j++){
			if(a[j]==a[j-1])num++;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
} 
