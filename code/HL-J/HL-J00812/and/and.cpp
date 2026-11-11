#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin >>a;
		if(i==n){
			cout<<a;
		}
	}
	return 0;
}