#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			sum=max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(n==m){
		sum=a[1];
		for(int i=1;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			sum=0;
			for(int j=1;j<=n;j++){
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
