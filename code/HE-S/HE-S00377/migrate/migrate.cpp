#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,x[2000005],ans;
void fs(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++) cin>>x[i];
	ll tot=x[n]-x[1];
	if(tot<=d){
		cout<<0;
		return;
	}
	if(d<tot){
		if(n%2==0){
			if(d>=n/2+1){
				cout<<n/2-1;
				return;
			}
			else{
				cout<<0;
				return;
			}
		}
		if(n%2==1){
			cout<<ceil(n/2)+1;
			return;
		}
	}
	cout<<n/d;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		fs();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
