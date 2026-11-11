//GZ-S00345 贵阳市南明区新世界学校 文希昊
#include<bits/stdc++.h>
using namespace std;

long long n,m,c,d,q,a_[50005];

struct c{
	long long k;
	long long a[50005],t[50005];
}w[50005];

struct g{
	int x,y;
}r[50005];

int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a_[i];
	}
	for(int i=1;i<=n;i++){
		cin>>w[i].k;
		for(int j=1;j<=w[i].k;j++){
			cin>>w[i].a[j]>>w[i].t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].x>>r[i].y;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;

}
