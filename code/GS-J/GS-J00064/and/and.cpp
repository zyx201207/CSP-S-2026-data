#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int max_=0;
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			int x=a[i]&a[j];
			cout<<x<<" ";
			max_=max(max_,x);
		}
	}
	cout<<max_;
	return 0;
}
