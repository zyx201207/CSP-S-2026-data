#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,l=0,ans=0;unsigned long long m,now=0;long long a;
	cin>>n>>m;
	vector<long long>N(n);
	for(int i=0;i<n;i++)cin>>N[i];
	sort(N.begin(),N.end());
	for(int i=0;i<n;i++){
		if(l!=i)now+=(i-l)*(N[i]-N[i-1]);
		while(l!=i&&now>m)
			now-=N[i]-N[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
