#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
signed main () {
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",a[i]);
	}
	sort(a+1,a+n+1,cmp); 
	int ans=a[1]; 
	m--;
	int k=2;
	while(m--){
		ans=(ans&a[k]);
		k++;
	}
	cout<<ans;
	
	
	return 0;
} 
