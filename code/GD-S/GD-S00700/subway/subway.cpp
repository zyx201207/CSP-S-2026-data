#include <bits/stdc++.h>
using namespace std;
int w[100005],a[100005],t[100005];
int main(){
//	freopen("subway.in","w",stdin);
//	freopen("subway.out","r",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;	
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k,sum=0;
	cin>>k;
	for(int i=0;i<2*k;i++){
		cin>>w[i]>>t[i];
		sum+=t[i];
	}
	cout<<sum;
//	fclose(stdin);
//	fclose(stdout);
}
