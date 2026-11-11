#include <iostream>
#include <algorithm>
#define Int long long
using namespace std;
Int n,A[500002],m;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>A[i];
	
	sort(A+1, A+1+n);
	
	Int Tot=0; int ans=2;
	for(; ans<=n; ans++){
		Tot+=(A[ans]-A[ans-1])*(ans-1);
		if(Tot>m) break;
	}
	
	cout<<ans-1;
	
	return 0;
}
