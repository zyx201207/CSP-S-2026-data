#include<bits/stdc++.h>
using namespace std;
const int Maxx=1e+7;
long long n,m,a[Maxx];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	cout<<a[m];
	return 0;
}

