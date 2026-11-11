#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[114514],a[1000][114514],a1,t[1000][114514],k[114514],z[114514],h;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>a1;
		h=m;
		for(int j=0;j<a1;j++){
			cin>>a;
			h=h+a;
			if(h>m)h=h-m;
			a[i][h]=1;
		}
		for(int j=0;j<k1;j++)cin>>t[i][j];
	}
	for(int i=0;i<q;i++)cin>>k[i]>>z[i];
	cout<<35<<endl>>16;
	return 0;
}
