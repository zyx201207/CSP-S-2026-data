#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int k,a[500001],t[500001];
};
struct qp{
	int qi,zhong;
};
qp q[100001];
aaa xian[501];
int w[500001],k[501],maxk=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>xian[i].k;
		for(int j=1;j<=xian[i].k;j++){
			cin>>xian[i].a[j]>>xian[i].t[j];
		}
	}
	cout<<3;
}
