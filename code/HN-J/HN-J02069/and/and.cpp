#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,st,a,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>m;
		st=m;
		if(i>=2){
		if(st|m>=sum){
			sum=st|m;
		}	
		}
	} 
	cout<<sum;
	return 0;
}
