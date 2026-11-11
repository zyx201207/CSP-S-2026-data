#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
const int INF=0x3f3f3f3f;
using namespace std; 
int n,m;
int a[N];
int sum[N];
int ans=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}cout<<endl;
	ans=a[n];
	while(m--){
		ans=ans^a[n--];
	}

	cout<<ans;
}
