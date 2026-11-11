#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int i=1;
	while(m>0){
		m-=a[i+1]-a[i];
		sum++,i++;
	}
	cout<<sum;
	return 0;
}
