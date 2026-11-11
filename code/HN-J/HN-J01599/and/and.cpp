#include<bits/stdc++.h>
using namespace std;
const int NN=2e5+10;
long long n,m,a[NN];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long res=a[n],h=0;
	for(int i=n;i>=1;i--){
		if(h>=m)break;
		res=res&a[i];
		h++;
	}
	cout<<res;
	
	return 0;
} 
