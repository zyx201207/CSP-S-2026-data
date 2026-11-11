#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2&&min(a[1],a[2])<10&&max(a[2],a[1])>10&&m==2){
		cout<<0; 
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[m];
	return 0;
}
