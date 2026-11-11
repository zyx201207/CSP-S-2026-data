#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
long long a[MAXN];
int main()
{
	freopen("and.in","r",stdin);
	freopen("andout","w",stdout);
	int n,m;
	cin>>n>>m;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		sum=a[1];
		for(int j=2;j<=n;j++){
			sum=sum&a[j];
		}
		cout<<sum;
		return 0; 
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	sum=a[n-m+1];
	for(int i=n-m+2;i<=n;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
