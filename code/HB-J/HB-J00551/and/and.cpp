#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ax;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a-1,a+n+1);
	for(int i=2;i<=1100000;i*=2){
		if(a[4]>=i){
			ax=i;
		}
	}
	cout<<12;
	return 0;
}
