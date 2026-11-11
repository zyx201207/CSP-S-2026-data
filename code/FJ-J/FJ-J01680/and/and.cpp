#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
	}
	int sum=a[1];
	if(m==n){
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	return 0;
}
