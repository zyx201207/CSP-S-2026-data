#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],k,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	k=a[2]-a[1];
	long long sum=0;
	while(true){
		sum++;
		long long c=sum*k;
		if(m<c)break;
		m-=c;
		ans++;
		if(m<c)break;
		m-=c;
		ans++;
	}
	cout<<ans;

	return 0;
} 
