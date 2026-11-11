#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,m,x,ans=INT_MAX;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i,){
		ans&=a[i];
	}
	cout<<ans;
	
	return 0;
}
