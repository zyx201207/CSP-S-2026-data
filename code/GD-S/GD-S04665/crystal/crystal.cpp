#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500000+10];
long long sum=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int x=a[i+1]-a[i];
		if(m>=x*i){
			sum++;
			for(int j=1;j<=i;j++){
				a[j]+=x;
				m-=x;
			}
		}
	}
	cout<<sum;
	return 0;
}
