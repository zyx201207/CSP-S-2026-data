#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int b[N];
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for(int i = 1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = i+1;j<=n;j++){
//			//从i->j暴力判断
//			if(a[j]*(j-i+1)-b[j]-b[i-1]<=m){
//				ans=max(ans,j-i+1);
//			}
//		}
//	}/
	//单调栈 
	deque<int>q;
	int j = 1;
	int len=0;
	for(int i = 1;i<=n;i++){
		//i表示从1->i 最多可行的次数
		if(len==0){
			j=i;
			len=1;
			continue;
		}else{
			len++;
		}
		while(b[j-1]>(b[i]+m)-(i-j+1)*a[i] && j<i){
			j++;
			len--;
		}
	//	cout<<b[j-1]<<' '<<(i-j+1)*a[i]-(b[i]+m)<<'\n';
//		cout<<i<<' '<<j<<'\n';
		ans=max(ans,i-j+1);
	}
	
	
	cout<<ans;
	
	return 0;
}
