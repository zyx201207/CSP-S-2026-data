#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10 ; 
int a[N];
bool cmp(int x,int b){
	return x>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans=(a[2]&a[1]);
	for(int i=3;i<=m;i++){
		ans&=a[i];

	}
	cout<<ans;
	return 0;
	
} 
