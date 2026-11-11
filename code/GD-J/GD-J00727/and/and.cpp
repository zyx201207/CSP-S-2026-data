#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	unsigned long long n,m,s;
	cin>>n>>m;
	unsigned long long a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	s=a[n-1];
	while(m--){
		s=(s&a[n-1]);
		n-=1;
	}
	cout<<s;
		
	return 0;
}

