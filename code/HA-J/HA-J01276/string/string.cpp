#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	vector<pair<int,int> > a(n);
	char aa;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>aa;
		a[i].second=aa-'a';
	}
	
	int ljishu=1;
	int rjishu=n;
	ll ans=0;
	while(ljishu<rjishu){
		if(a[rjishu].first>a[ljishu].first){
			if(a[rjishu].second!=a[ljishu].second){
				ans+=a[ljishu].first;
			}
			a[rjishu].first-=a[ljishu].first;
			a[ljishu].first=0;
			ljishu++;
		}
		else if(a[rjishu].first<a[ljishu].first){
			if(a[rjishu].second!=a[ljishu].second){
				ans+=a[rjishu].first;
			}
			a[ljishu].first-=a[rjishu].first;
			a[rjishu].first=0;
			rjishu--;
		}
		else if(a[rjishu].first==a[ljishu].first){
			if(a[rjishu].second!=a[ljishu].second){
				ans+=a[ljishu].first;
			}
			a[rjishu].first=0;
			a[ljishu].first=0;
			ljishu++;
			rjishu--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
