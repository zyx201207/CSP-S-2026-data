#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	int o=s[n-1];
	for(int j=1;j<m;j++){
		o=o&s[n-j-1];
	}
	//o=12&12;
	cout<<o;
	return 0;
}
