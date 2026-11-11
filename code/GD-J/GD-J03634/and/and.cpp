#include<bits/stdc++.h>
using namespace std;
int n[6767];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin >>a>>b;
	for(int i=0;i<a;++i)cin >>n[i];
	sort(n,n+a);
	if(b=1)cout <<n[a-1];
	else cout <<n[0];
	return 0;
}
