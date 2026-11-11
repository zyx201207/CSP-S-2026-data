#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0){
		cout<<3;
		break;
	}
	else {
		cout<<4;
		break;
	}
	}
	
	
	
	
	return 0;
}
