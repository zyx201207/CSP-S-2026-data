#include <bits/stdc++.h>
using namespace std;
long long a[500005];
bool c(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,c);
	long long sum=0;
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum=sum&a[i];	
	}
	cout<<sum;
	return 0;
}
