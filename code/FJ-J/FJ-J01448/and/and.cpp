#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],l[200005],k=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>n-m;i--){
		l[k]=a[i];
		k++;
	}
	cout<<l[k-1];
	return 0;
}
