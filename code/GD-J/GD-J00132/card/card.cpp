#include<bits/stdc++.h>
using namespace std;
int n,m,num[500010];
int ans[300010];
vector<int>a;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			int cnt=num[j];
			for(int k=0;k<a.size();k++){
				if(a[k]==cnt){
					int nnnnnnn=a.size()-1;
					for(int q=nnnnnnn;q>=k;q--){
						a.erase(a.begin()+q);
					}
					break;
				}
			}
			a.push_back(cnt);
//			for(int j=0;j<a.size();j++){
//				ans[a[j]]++;
//				cout<<a[j]<<' ';
//			}
//			cout<<'\n';
		}
		//cout<<'\n';
		for(int j=0;j<a.size();j++){
			ans[a[j]]++;
			//cout<<a[j]<<' ';
		}
		//cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<(i==m?'\n':' ');
	}
	return 0;
}
//3
