#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e9+10,NINF=-1e9-10,N=5*1e5+10;
ll n,m,a[N],b[N],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cout<<n<<endl;
	if(n<=1){
		cout<<0<<endl;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(ll i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(ll i=2,l;i<=n;i++){
		l=i-1;
		while(i!=n&&a[i+1]==a[i]){
			i++;
		}
		if(m==0){
			ans=max(ans,i-l);
			continue;
		]
		for(ll temp;l>0;l--){
			temp=a[i]*i-(b[i]-b[l-1]);
			if(temp<=m){
				ans=max(ans,i-l+1);
			}
			else continue;
		}
	}
	cout<<ans<<endl;
	return 0;
}
