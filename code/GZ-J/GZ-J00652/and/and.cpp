//GZ-J00652 ует╙Ог 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],m,jg;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n,greater<long long>());
	for(long long i=1;i<m;i++){
		jg=a[i]&a[i+1];
	}
	cout<<jg<<endl;
	return 0;
}

