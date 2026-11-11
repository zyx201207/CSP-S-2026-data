#include<bits/stdc++.h>
using namespace std;
long long n,x,m,max1,a[1000005],ans;
priority_queue<int>q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		q.push(x);
	}
	for(int i=1;i<=m;i++){
		a[i]=q.top();
		q.pop();
	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;	
}