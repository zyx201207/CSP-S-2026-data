#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[3000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		sort(a+1,a+n+1);
		cout<<a[1];
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==1){
		cout<<a[1];
		return 0;
	}
	cout<<a[2];
	return 0;
}
