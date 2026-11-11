#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long n[a];
	for(long long i=0;i<a;i++)cin>>n[i];
	sort(n,n+a);
	long long m=n[a-2],j=n[a-1],k=a-2;
	b--;
	while(b--){
		m=m&j;
		j=n[k-1];
		k--;
	}
	cout<<m;
	return 0;
}
