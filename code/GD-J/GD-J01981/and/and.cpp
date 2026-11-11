#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[n];
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;++i)ans&=a[i];
		cout<<ans;
	}
	else if(m==n-1){
		int ans=0;
		for(int i=1;i<=n;++i){
			int cnt; 
			if(i==1)cnt=a[2];
			else cnt=a[1];
			for(int j=1;j<=n;++j){
				if(j!=i)cnt&=a[j];
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;++i){
			int cnt=0;
			for(int j=1;j<=n;++j){
				if(i!=j){
					cnt=max(cnt,a[i]&a[j]);
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	else{
		int ans=a[1];
		for(int i=2;i<=m;++i)ans&=a[i]; 
		cout<<ans;
	}
	return 0;
}
