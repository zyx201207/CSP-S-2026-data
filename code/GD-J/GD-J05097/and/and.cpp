#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,maxx;
struct Node{
	int sum,cnt;
} dp[N];
int a[N];
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
	}
	if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
	}
	if(m==2){
		sort(a+1,a+n+1,greater<int>());
		dp[1].sum=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				cout<<a[i];
				return 0;
			}
			dp[i].sum=a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,i&j);
			}
		}
		cout<<maxx;
	}
	return 0;
}
