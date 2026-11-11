#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200010;
int n,m,a[N];
bool flag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int t=29;t>=0;t--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(flag[i])continue;
			if((a[i]>>t)&1)cnt++;
		}
		if(cnt>=m){
			ans+=1<<t;
			for(int i=1;i<=n;i++)if(((a[i]>>t)&1)^1)flag[i]=1;
		}
	}
	cout<<ans;
	return 0;
}

