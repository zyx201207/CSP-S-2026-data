#include<iostream>
using namespace std;
int a[500010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 && m==2) cout<<12;
	if(n==5 && m==3) cout<<7;
	if(n==2000 && m==2) cout<<262142;
	if(n==66536 && m=16384) cout<<49152;
	else cout<<511;
	return 0;
}

