#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int s=1;
	for(int i=n-1;i>=0;i++){
		s&=a[i];
	}
	cout<<s;
	return 0;
}
