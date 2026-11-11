#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool teshu(){
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1])return false;
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(teshu()){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
	}
	return 0;
}
