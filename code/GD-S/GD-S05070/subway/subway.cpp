#include<bits/stdc++.h>
using namespace std;
int main(){
	long long q,c,n,m,d,s;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	long long w[m],a[10000],k[10000],t[10000],x,y;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(long long r=1;r<=q;r++){
		s=1;
		cin>>x>>y;
		long long z=y;
		while(z!=0){
			s+=t[z];
			z--;
		}
		cout<<s+w[1]+t[2]+w[y]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
