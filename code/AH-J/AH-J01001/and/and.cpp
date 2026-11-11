#include <bits/stdc++.h>
using namespace std;
	int n, m,ans=-1e9,cnt;
	long long s[200010];
	bool vis[200010];
void myand(int t){
	if(t>m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			if(t==1)
				cnt=s[i];
			int lcnt=cnt;
			vis[i]=true;
			cnt=cnt&s[i];
			myand(t+1);
			vis[i]=false;
			cnt=lcnt;
		}
	}
}
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	myand(1);
	cout<<ans;
	return 0;
}
