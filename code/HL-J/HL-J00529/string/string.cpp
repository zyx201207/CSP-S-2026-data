#include<iostream>
using namespace std;
struct zz{
	long long lef,rig,zl;
	char wh;
}a[200001];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c;
	long long l=0,r=0,k=0,f=0;
	char b,k1;
	bool n1=false;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i].zl>>b;
		if(i==1) k1=b;
		if(k1!=b) n1=true;
		l=r+1;
		r+=a[i].zl;
		a[i].wh=b;
		a[i].lef=l;
		a[i].rig=r;
	}
	if(n1==false){
		cout<<0;
		return 0;
	}
//	for(int i=1; i<=n; i++){
//		if(a[i].lef<=r/2 && a[i].rig>=r/2){
//			k=i;
//			break;
//		}
//	}
//	long long k2=n;
//	for(int i=1; i<=k; i++){
//		long long r1=n-a[i].lef+1,l1=n-a[i].rig+1;
//		while(a[k2].lef<=r1 && a[k2].rig>=l1){
//			int x=a[i].wh,y=a[k2].wh;
//			long long l2=max(l1,a[k2].lef),r2=min(r1,a[k2].rig);
//			if(x!=y) f+=r2-l2;
//			if(a[k2].lef>l1) k2--;
//			else break;
//		}
//	}
	cout<<r/2;
	return 0;
}
