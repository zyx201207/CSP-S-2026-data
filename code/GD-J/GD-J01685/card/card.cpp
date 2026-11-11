#include <bits/stdc++.h>
using namespace std;
int a[500005];
int cnt1[300005];
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>=a[i]) flag=0;
	}
	if(flag){
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<int> sta;
		int cnt[300005];
		for(int j=i;j<=n;j++){
			cnt[a[i]]++;
			if(cnt[a[i]]>1){
				while(sta.top()!=a[i]) sta.pop();
			}else sta.push(a[i]);
		}
		while(sta.size()!=0){
			cnt1[sta.top()]++;
			sta.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt1[i]<<" ";
	}
	return 0;
}
