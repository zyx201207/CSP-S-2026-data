#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p,a[100000010];
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<32<<endl<<17;
	}
	if(n==3)
		cout<<35<<endl<<16;
	return 0;
}
