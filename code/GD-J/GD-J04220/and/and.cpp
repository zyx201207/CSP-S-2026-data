#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int tmp=a[n];
	for(int i=n;i>=n-m+1;i--){
		tmp&=a[i];
	}
	cout<<tmp;
}
