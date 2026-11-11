#include<bits/stdc++.h>
using namespace std;
long long a,m,n[10005],g;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>m;
	for(int i=1;i<=a;i++){
	    cin>>n[i];
	    g=n[i];
	}
	cout<<g;
	return 0;
}
