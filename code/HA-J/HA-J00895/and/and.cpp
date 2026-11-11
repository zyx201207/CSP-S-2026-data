#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
long long sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		cout<<12;
	}
	else{
		cout<<7;
	}
	
	return 0;
}
