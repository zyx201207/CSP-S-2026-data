#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,n,m,sum=0;
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>a;
	}
	for(int i=1;i<=n;i++){
			sum+=a;
	} 
	cout<<sum;
	return 0;
} 
