#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int mx=a[0];
	for(int i=1;i<m;i++){
		cout<<mx<<endl;
		mx=a[i] & mx;
	}
	cout<<mx;
	return 0;
}
