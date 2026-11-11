#include<bits/stdc++.h>
using namespace std;
long long a[200100],ans=2e9-1;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long op,k;
	cin>>op>>k;
	for(long long i=1;i<=op;i++){
		cin>>a[i];
	}
	sort(a+1,a+op+1);
	for(long long i=op;i>op-k;i--){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 2
3 12 12 15
*/
