#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt[500005],ans[500005];
deque<int> d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		d.clear();
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<=n;j++){
			if(!cnt[a[j]]){
				cnt[a[j]]++;
				d.push_back(a[j]);
			}
			else{
				while(d.back()!=a[j]){
					d.pop_back();
				}
				cnt[a[j]]--;
			}
		}
		for(int j=0;j<d.size();j++){
			ans[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
