#include<bits/stdc++.h>
using namespace std;
const int N=2001;
long long a[N];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int T=1;
	while(T<=n){
		cin>>a[T];
	}
	sort(a+1,a+n+1);
	cout<<a[m];
	return 0;
}
