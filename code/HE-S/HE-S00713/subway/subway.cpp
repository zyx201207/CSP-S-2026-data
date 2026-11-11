#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int num=0;
	for(int i=0;i<d;i++){
		int s;
		cin>>s;
		num=num+s;
	}
	for(int i=1;i<=n;i++){
		cout<<(num-m+d)/n+i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
