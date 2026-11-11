#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200000],ans;
bool f(int a,int b){
	return a>=b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,f);
	ans=a[0];
	for(int i=1;i<m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
