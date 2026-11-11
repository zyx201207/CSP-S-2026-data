#include<bits/stdc++.h>
using namespace std;
const int M=5*1e5+5,N=505;
int m,n,c,d,q;
int w[M],a[M],t[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>t[i];
	}
	cout<<t[1]*n<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
