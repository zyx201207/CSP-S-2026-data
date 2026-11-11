#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void dyr(){
	ll n,m,nw=0,chs=0;
	cin>>n>>m;
	vector<ll> a(n+2),b(n),sum(n+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a.begin()+1,a.end()-1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+b[i];
	}
	ll ans=0;
	for(int i=1;i<n;i++){
		ans=max(ans,chs);
		
		while(nw+(chs+1)*b[i]>m){
			
			nw-=sum[i-1]-sum[i-chs-1];
			chs--;
		}
		chs++;
		nw+=chs*b[i];
	}cout<<ans+1;
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	dyr();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
