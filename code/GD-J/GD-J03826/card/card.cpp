#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],cnt[N],ans[N],s[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>> n >> m;
	bool isspec=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i]=1;
		if(a[i]!=a[i-1]&&a[i]!=a[i-1]+1) isspec=0;	
	}
	if(isspec){
		int lstp=1,sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]) s[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			sum=s[i]+sum;
			cout << sum<<" "; 
		} 
		return 0;
	}
	deque<int> q;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!cnt[a[j]]){
				q.push_back(a[j]),cnt[a[j]]++;
			}else{
				int u=q.back();
				do{
					u=q.back();
					cnt[u]--;
					q.pop_back();
				}while(u!=a[j]);
				q.push_back(a[j]),cnt[a[j]]++;
			}
		}
		while(q.size()){
			int u=q.back();
			q.pop_back();
			ans[u]++,cnt[u]--;
		}
	}
	for(int i=1;i<=m;i++) cout << ans[i]<<" ";
	return 0;
}
