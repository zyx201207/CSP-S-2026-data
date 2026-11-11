#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int cnt[114514];
char alp[114514];
char c[1145144];
int L;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		L+=cnt[i];
		cin>>alp[i];
	}
	int idx=1;
	for(int i=0;i<=n;i++){
		for(int j=1;j<=cnt[i+1];j++){
			c[idx++]=alp[i+1];
		}
	}
	//c[i]数组代表着当前回文串，内存由0到idx-1
	for(int i=1;i<=idx;i++){
		if(c[i]!=c[L+1-i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
