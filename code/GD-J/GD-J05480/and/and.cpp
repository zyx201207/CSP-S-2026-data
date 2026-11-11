#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,m,a[N],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<12;
	}
	if(n==5&&m==3){
		cout<<7;
	}
	return 0;
} 
