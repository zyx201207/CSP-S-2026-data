#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],sum = 4095,num,vis[200005];
long long maxs = 0;


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		sum = a[1];
		for(int i = 1;i<=n;i++){
			sum = sum&&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==n-1){
		sort(a+1,a+n+1);
		sum = a[2];
		for(int i = 2;i<=n;i++){
			sum = sum&&a[i];
		}
		return 0;
	}

	return 0;
}
