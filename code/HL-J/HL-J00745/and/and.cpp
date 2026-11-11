#include<bits/stdc++.h>;
using namespace std;
int a[200010],b[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=n-1;i>=m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
	
}