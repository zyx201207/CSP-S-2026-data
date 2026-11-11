#include<bits/stdc++.h> 
using namespace std;
int n,m,a[200005],ans;
int check(int x){
	int y=x;
	for(;y>0;y/=2)
		if(y%2==0)
			return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1)
		cout<<a[n];
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans=(ans&a[i]); 
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,(a[i]&a[j]));
		cout<<ans;
	}
	else if(check(a[n])==1)
		cout<<a[n-m+1];
	else{
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
			ans=(ans&a[i]);
		cout<<ans;
	}
	return 0;
}
