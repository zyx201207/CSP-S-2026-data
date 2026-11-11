#include<bits/stdc++.h> 
using namespace std;
long long w[500005],k,a,t;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k;
		for(long long j=0;j<k;j++) cin>>a>>t;
	}
	long long x,y;
	long long ans[500005];
	for(int i=0;i<q;i++){
		cin>>x>>y;
		ans[i]+=w[x-1]+w[y-1];
		ans[i]+=t*100;
	}
	for(int i=0;i<q;i++) cout<<ans[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}