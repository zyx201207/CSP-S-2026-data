#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
bitset<N> bt[40];
bitset<N> ans;
ll a[N];	
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int k=0;k<31;k++){
			if(a[i]&(1<<k)) bt[k][i]=1;
		}
		ans[i]=1;//初始化 
	}
	for(int k=30;k>=0;k--){//优先拿大的 
		if(bt[k].count()<m) continue;//根本没有m个能与到的TAT
		else{
			if((ans&bt[k]).count()<m) continue;
			else ans&=bt[k];
		}
	}
	ll ans_=2147483647;
	for(int i=0;i<n;i++){
		if(ans[i]) ans_&=a[i];
	} 
	cout<<ans_<<endl;
	
	
	
	
	return ;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
