#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=1;
	priority_queue<long long>x;
	int c=1;
	for(int i=1;i<n;i++){
		c=0;
		ans=1;
		for(int j=i+1;i<=n;j++){
			if(c<m){
				ans=ans&a[i]&a[j];
				c++;
			}
			x.push(ans);
		}
	}
	cout<<x.top();
	return 0;
}
