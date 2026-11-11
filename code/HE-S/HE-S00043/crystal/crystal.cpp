#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n,m;
int a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int j=1;j<=n;j++){
		int j1=a[j],sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(j1-a[i]>=0&&sum+j1-a[i]<=m){
				sum+=j1-a[i];
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
