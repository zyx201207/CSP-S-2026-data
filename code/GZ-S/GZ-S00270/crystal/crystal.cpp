//GZ-S00270 贵阳三中 王志栋 
#include<bits/stdc++.h>
using namespace std;

int n,m,ans = 0;
//dfs(int x){
//	
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<int>a(n + 1);
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
//	for(int i = 1;i <= n;i++){
//		cout<<a[i]<<" ";
//	}
	int l = 1,r = n;
	while(l <= r){
		int mid = (l + r) / 2;
		int s = 0;
		for(int i = 1;i <= mid - 1 ;i++){
			s += a[mid] - a[i];
		}
		if(s > m){
			r = mid - 1;
		}
		else{
			ans = max(ans,mid);
			l = mid + 1;
		}
	}
	cout<<ans;
}
