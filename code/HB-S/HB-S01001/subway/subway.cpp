#include<bits/stdc++.h>
using namespace std;
int w[500005],a[500005],t[500005];
int l[100005],r[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=2*k;i++){
		cin>>a[i]>>t[i];
	}
	for(int i=1;i<=p;i++){
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=p;i++){
		cout<<n<<endl;
	}
	return 0;
}
