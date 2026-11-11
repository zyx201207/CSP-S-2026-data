#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	int a,b;
	cin>>a>>b;
	cin>>n>>m;
	if(n==m){
		cout<<'1';
	}
	for(int i=1;i<=5*18;i++){
		if(a&&b==i){
			cout<<'1';
		}
	}
	return 0;
} 
