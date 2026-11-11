#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans,tot,ls;
bool t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]-a[i-1]!=a[2]-a[1]) t=1;
	}
	if(!t){
		for(int i=n-1;i>=1;i--){
			tot+=a[n]-a[i];
			if(tot>m) break;
			else ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		tot=0;
		for(int j=i-1;j>=1;j--){
			tot+=a[i]-a[j];
			if(j==1){
				ls=i-j+1;
				ans=max(ans,ls);
				break;
			}else if(tot>m){
				ls=i-j;
				ans=max(ans,ls);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
