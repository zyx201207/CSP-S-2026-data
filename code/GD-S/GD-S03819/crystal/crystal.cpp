#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 500005;

ll a[MAXN];
int n,ans=1;
ll m;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	int nowAns=0;
	for(int i=2;i<=n;i++){
		nowAns=1;
		int j=i-1;
		ll curNum = m;
		while(j>=1){
			if((a[i]-a[j])>curNum){
				break;
			}
			curNum-=(a[i]-a[j]);
			nowAns++;j--;
		}
		ans=max(nowAns,ans);
	}
	cout<<ans;
	
	
	return 0;
}
