//GZ-J00717 бюН№бз КывужабЇ 
#include <bits/stdc++.h>
using namespace std;

long long n,m;
int a[200050],a2[];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n,m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if(m==1){
		long long maxa;
		for(int i=1;i<n;i++)
			maxa=max(a[i],a[i+1]);
		cout<<maxa<<endl;
	}
	else cout<<a[n];
	return 0;
}
