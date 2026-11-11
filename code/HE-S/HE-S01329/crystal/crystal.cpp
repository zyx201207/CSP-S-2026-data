#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5+5;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=1;
	int a[N]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long k=m,j=1;
	while(k!=0){
		int x=(a[j+1]-a[j]);
		if(x*j<=k){
			k-=x*j;
			cnt++;
			a[j]+=k;
		}
		j++;
	}
	for(int i=j+1;i<=n;i++){
		if(a[i]==a[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
