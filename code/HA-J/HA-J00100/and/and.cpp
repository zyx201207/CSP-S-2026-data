#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	set<int>s;
	for(int i=1;i<=n;i++)s.insert(i);
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++)if((a[j]&1<<i)&&s.count(j))cnt++;
		if(cnt>=m)for(int j=1;j<=n;j++)if(!(a[j]&1<<i)&&s.count(j))s.erase(j);
	}
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++)ans&=a[*it];
	cout<<ans;
	return 0;
}
