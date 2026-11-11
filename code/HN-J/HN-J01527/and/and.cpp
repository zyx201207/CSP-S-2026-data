#include<iostream>
using namespace std;
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for (int j=1;j<m;j++){
			ans=max(a[i]&a[j+i],ans);
		}
	}
	cout<<ans;
	return 0;
}
