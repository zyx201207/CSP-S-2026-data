#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N],x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,maxn=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=abs(a[i]-a[i-1]);
	}
	
	cout<<maxn+1;
	return 0;
}
