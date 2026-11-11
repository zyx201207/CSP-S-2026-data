#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,num[maxn],ans,m;
char c[maxn];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		m+=num[i];
		cin>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		int t=min(num[l],num[r]);
		if(c[l]!=c[r])ans+=t;
		num[l]-=t,num[r]-=t;
		if(num[l]>num[r])r--;
		else l++;
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)solve(); 
	return 0;
}
