#include<bits/stdc++.h>
using namespace std;
long long n,m,a[514514],b[514514],ans=1;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) 
	{	
		m-=i*(a[i+1]-a[i]);
		cout<<m<<' ';
		if(m<0) break;
		ans++;
	}
	cout<<ans;
	return 0;
}

