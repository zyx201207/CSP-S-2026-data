#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int n,m,a[N],b=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>b)b=a[i];
	}
	cout<<b;
	return 0;
} 
