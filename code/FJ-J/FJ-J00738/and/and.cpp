#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[200005],s,i;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	s=a[n];
	i=1;
	while(i<m){
		s=(s&a[n-i]);
		i++;
	}
	cout<<s;
	return 0;
}
