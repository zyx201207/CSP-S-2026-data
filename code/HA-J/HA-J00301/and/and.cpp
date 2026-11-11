#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 7;
const int NP = 1 << 20;
//172.16.12.5
int arr[N],n,m;
int ANS;
inline void dfs1(int num,int cnt,int ans){
//	cout<<num<<' '<<cnt<<' '<<ans<<' '<<endl;;
	if(num > n || cnt > m){
		return;
	}
	if(cnt == m){
//		cout<<num<<' '<<cnt<<' '<<ans<<' '<<endl<<endl;;;
		ANS = max(ANS, ans);return;
	}
	if(!cnt){
		ans = arr[num];
	}
	dfs1(num+1,cnt+1,ans & arr[num]);
	dfs1(num + 1,cnt, ans);
}
inline void dfs(int num,int cnt,int ans){
//	cout<<num<<' '<<cnt<<' '<<ans<<' '<<endl;;
	if(num > n || cnt > m){
		return;
	}
	if(cnt == m){
//		cout<<num<<' '<<cnt<<' '<<ans<<' '<<endl<<endl;;;
		ANS = max(ANS, ans);return;
	}
	if(!cnt){
		ans = arr[num];
	}
	dfs(num+1,cnt+1,ans & arr[num + 1]);
	dfs(num + 1,cnt, ans);
}
main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	cin>>m;
	for(int i = 1;i<=n;++i){
		cin>>arr[i];
	}
	if(m ==2){
		dfs1(1,0,0);
		dfs1(1,1,arr[1]);
		cout<<ANS<<endl;
	}
	else{
		dfs(1,0,0);
		dfs(1,1,arr[1]);
		cout<<ANS<<endl;
	}
}