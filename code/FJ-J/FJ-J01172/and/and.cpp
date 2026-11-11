#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,anss,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		anss=min(anss,x);
	}
	cout<<anss;
	return 0;
}
