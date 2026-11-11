#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1]<<endl;
		return 0;
	}
	for(int i=2;i<=m;i++){
		ans=a[i]&a[i]-1;
	}
	cout<<ans<<endl;
	return 0;
}
