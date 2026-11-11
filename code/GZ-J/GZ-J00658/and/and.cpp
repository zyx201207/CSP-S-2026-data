//GZ-J00658 陈泓澍 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000005];
int main(){
	
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int x=a[n];
	for(int i=n;i>=n-m+1;i--){
		if(a[i]<=x) x=a[i];
	}
	cout<<x;
	return 0;
}
