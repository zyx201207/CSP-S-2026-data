#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[500005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=1;
	while(m>=0){
		long long sum=0;
		sum+=i*(a[i]-a[i-1]);
		m-=sum;
		i++;
	}
	cout<<i;
	return 0;
}
