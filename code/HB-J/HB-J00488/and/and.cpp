#include <bits/stdc++.h>
using namespace std;
int n,a[100005],m,maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}
	if(m==2){
		for(int i=0;i<n;i++){
			a[i]&=a[i+1];
		}
		sort(a,a+n);
		cout<<a[n-1];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a[i]&=a[i+1];
		}
	}
	sort(a,a+n);
	cout<<a[n-1];
	return 0;
}
