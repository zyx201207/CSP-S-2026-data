#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int n,m;
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int cnt=0;
		int p=m;
		for(int j=i-1;j>=1;j--){
			int t=a[i]-a[j];
			if(t<=p){
				p-=t;
				cnt++;
			}
			else break; 
			if(m==0) break;
		}
		ans=max(ans,cnt+1);
		if((i-1)<=ans) break;
	}
	cout<<ans;
	return 0;
}
