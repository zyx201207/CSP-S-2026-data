#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n-1;i>=1;i--)
		b[i]=b[i+1]+a[i+1]-a[i];
	int k=1,p=abs(a[2]-a[1]);
	for(int i=2;i<=n;i++)
		if(m>=k*p){
			k++;
			m-=k*p;
		}
	cout<<k;
	return 0;
}
