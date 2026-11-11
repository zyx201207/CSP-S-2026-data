#include<bits/stdc++.h>
namespace KH{
using namespace std;
#define int long long
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1),b(m+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	vector<int> ans(m+1);
//	ans[a[n]]=n;
//	for(int l=1,r=n;l<=n&&l<r;l++){
//		if(b[a[r]]==1){
//			while(b[a[r]]<2&&r>=l) r--,ans[a[r]]+=(r-l+1);
//		}
//		b[a[l]]--;
//		for(int i=1;i<=m;i++){
//			cout<<ans[i]<<" \n"[i==m];
//		}
//	}
	for(int l=1;l<=n;l++){
		stack<int> owo;
		unordered_map<int,bool> mp;
		for(int r=l;r<=n;r++){
			if(mp[a[r]]){
				while(!owo.empty()&&a[owo.top()]!=a[r]) mp[a[owo.top()]]=0,owo.pop();
				owo.pop();
			}
			owo.push(r),mp[a[r]]=1;
		}
		while(!owo.empty()) ans[a[owo.top()]]++,owo.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" \n"[i==m];
	}
}
void main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	while(T--){
		solve();
	}
}
#undef int
}
int main(){KH::main();}
