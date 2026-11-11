#include<bits/stdc++.h>
using namespace std;
const int N=200005;
#define int long long
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m-1;i++){
		ans=a[i]&a[i+1];
	}
	cout<<ans;
	   
	   return 0;
}

