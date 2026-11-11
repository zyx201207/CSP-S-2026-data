#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[200009];
bool no[200009];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
	}
	memset(no,0,sizeof no);
	for(int i = 29;i>=0;--i){
		int cnt = 0;
		for(int j = 1;j<=n;++j){
			if(no[j]) continue;
			if((a[j]&(1<<i))) cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j = 1;j<=n;++j){
				if(no[j]) continue;
				if((a[j]&(1<<i)) == 0) no[j] = 1;
			}	
		}
	}
	cout<<ans;
}
