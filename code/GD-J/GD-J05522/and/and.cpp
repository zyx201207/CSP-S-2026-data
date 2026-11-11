#include <bits/stdc++.h>
using namespace std;
string aejz;
int n,m,a[200002],i=0;
char b[200002];
string ejz(int x){
	while(x>1){
		aejz+=x%2;
		x=x/2;
		i++;
	}
	aejz[i]=1;
	return aejz;
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ejz(a[i]);
	}
	
	return 0;
}
