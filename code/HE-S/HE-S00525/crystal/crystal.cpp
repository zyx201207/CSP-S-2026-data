#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	int cnt=1,i=1;
	while(m>=cnt*c[i]&&i<n&&cnt<=n){
		m-=cnt*c[i];
		cnt++;
		i++;
	}
	cout<<cnt;
	return 0;
}

