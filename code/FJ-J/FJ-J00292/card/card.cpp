#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n=0,m=0;
ll a[500009],answer[500009];
map<ll,ll> mp;
int ans[500009][3];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//system("diff a.in b.in");
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=m;i>=1;i--){
		if(mp.count(a[i])){
			if(ans[mp[a[i]]][2]!=mp[a[i]]+1){
				ans[i][2]=mp[a[i]],ans[ans[mp[a[i]]][2]][1]++,mp[a[i]]=ans[mp[a[i]]][2];
			}
			else{
				ans[i][2]=mp[a[i]]+1,ans[mp[a[i]]+1][1]++,mp[a[i]]=i;
			}
		}
		else{
			ans[i+1][1]++,ans[i][2]=i+1;mp[a[i]]=i;
		}
		ans[i][0]=a[i];
	}
	//for(int i=1;i<=m;i++)cout<<i<<":  "<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<'\n';
	//cout<<endl;
	for(int i=1;i<=m;i++){
		answer[ans[i][0]]+=ans[i][1]+1;
		//cout<<ans[i][0]<<' '<<ans[i][1]+1<<'\n';
		ans[ans[i][2]][1]+=ans[i][1];
		//cout<<ans[i][2]<<":  "<<ans[ans[i][2]][0]<<' '<<ans[ans[i][2]][1]<<' '<<ans[ans[i][2]][2]<<'\n';
	}
	for(int i=1;i<=n;i++)cout<<answer[i]<<' ';
	return 0;
}


