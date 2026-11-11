#include<bits/stdc++.h>
using namespace std;
int m,n,a[200010],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	s=a[1];
	if(m==n){
		for(int i=2;i<=n;i++)s=s&a[i];
		cout<<s;
	}else{
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	return 0;
}
