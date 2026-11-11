#include <iostream>
#include <algorithm>
using namespace std;
int n,m, A[200002];
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);	
	
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>A[i];
	
	sort(A+1, A+1+n, cmp);
	
	int ans=A[1]&A[2];m-=2;
	int p=3;
	while(m--){
		ans&=A[p++];
	}
	
	cout<<ans;
	
	return 0;
}
