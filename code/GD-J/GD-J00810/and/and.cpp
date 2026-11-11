#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],l[200005],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=17;i>=0;i--){
		vector<int>ll;
		int k=(1<<i),lx=0;
		for(int j=1;j<=n;j++){
			if(l[j])continue;
			if(a[j]&k)lx++;
			else ll.push_back(j);
		}
		if(lx>=m){
			ans+=k;
			for(int e:ll)l[e]=1;
		} 
	}
	cout<<ans;
}
