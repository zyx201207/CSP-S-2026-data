#include<bits/stdc++.h>
using namespace std;
const int ml=2*1e5+5;
long long ans,a[ml],n,m;
int w(int a){
	
}
bool cmp(long long p1,long long p2){
	
}
int main(){
	freopen("and4.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	
	ans=a[n];
	for(int i=1,j=n-1;i<m;i++,j--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

