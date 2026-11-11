#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int b=1;
	for(int i=n-1;i>=0;i--){
		if(b==m){
			cout<<a[i];
			return 0;
		}
		b++;
	}
	return 0;
}
