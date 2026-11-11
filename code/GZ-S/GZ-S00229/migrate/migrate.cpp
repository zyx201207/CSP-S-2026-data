//GZ-S00229 ³ÂÑåÑ®
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll c,t,n,d,a[N],tp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(a[2]-a[1]==1)cout<<n-2*d+1<<'\n';
			if(a[2]-a[1]==2)cout<<(d>=3?n-d+(d%2==0?2:3):0);
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		if(n<=3){
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1&&a[i-1]+d<a[i]){
				tp[i-1]=1;
				tp[i]=1;
			}
		}
		
	}
	return 0;
}
