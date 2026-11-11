#include <bits/stdc++.h>
using namespace std;
const int max1=200001;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[max1];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==1){
		cout<<n/2+1;
	}else{
		cout<<n/2;
	}
	return 0;
}
