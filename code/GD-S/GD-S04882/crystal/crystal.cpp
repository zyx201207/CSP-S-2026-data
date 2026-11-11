#include<bits/stdc++.h>
using namespace std;
int a[20005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m%2==0){
		cout<<m/2;
	}
	if(m%2==1){
		cout<<m/2+1;
	}
	return 0;
}

