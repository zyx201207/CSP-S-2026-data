#include<bits/stdc++.h>
using namespace std;
const int T=1e5+5;
int se[T];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>se[i];
	}
	sort(se,se+n);
	int num=se[0];
	for(int i=1;i<m;i++){
		num=num and se[i];
	}
	cout<<se[n-m];
	cout<<"\n";
	return 0;
}
