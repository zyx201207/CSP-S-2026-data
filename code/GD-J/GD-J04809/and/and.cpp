#include<bits/stdc++.h>
using namespace std;
int a[2000090];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long sum=a[n];
	m--;
	for(int i=n-1;;i--){
		sum=sum&a[i];
		m--;
		if(m==0)
		{
			break;
		}
	}
	cout<<sum;
	return 0;
}
