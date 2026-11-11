#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b=a[2]-a[1];
	int i=1;
	while((i*i+i)/2*b<n){
		i++;
	}
	cout<<i;
	return 0;
}