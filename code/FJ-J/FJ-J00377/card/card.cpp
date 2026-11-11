#include<bits/stdc++.h>
using namespace std;
int a[300005],cnt[500005];
set<int> g;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		vector<int>h(n+5);
		int step=0;
		for(int j=step+i;j<n;j++){
			h[i]=a[j];
			for(int i=0;i<h.size();i++){
				cnt[h[i]]++;
			}
		}
		step++;
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==0) continue;
		cout<<cnt[i]<<" ";
	}
	return 0;
}
