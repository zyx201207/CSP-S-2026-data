#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,pow2[32]={1};
vector<int> cnt[32],res;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		int maxn=-1e9;
		for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
	}
	else{
		for(int i=1;i<=30;i++)pow2[i]=pow2[i-1]<<1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=30;j++){
				if(pow2[j]&a[i])cnt[j].push_back(i);
			}
		}
		for(int i=30;i>=0;i--){
			if(cnt[i].size()>=m){
				for(int j=0;j<cnt[i].size();j++)res.push_back(a[cnt[i][j]]);
				sort(res.begin(),res.end());ans=res[res.size()-1];
				for(int j=res.size()-2;res.size()-j<=m;j--)ans&=res[j];
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
