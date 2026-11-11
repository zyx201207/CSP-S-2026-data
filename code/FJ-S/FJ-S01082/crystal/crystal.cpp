#include<bits/stdc++.h>
using namespace std;
long long n,m,q,sum=1;
int a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		q+=(a[i]-a[i-1])*(i-1);
		if(q<=m){
			sum=i;
		}else{
			cout<<sum;
			return 0;
		}
	}
	cout<<sum;
	return 0;
}

