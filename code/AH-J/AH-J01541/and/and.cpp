#include "bits/stdc++.h"
using namespace std;
#define LL long long
const int N=2e5+5;
LL myy[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};

struct node{
	LL num,mark;
	bool two[32];
}a[N];

bool cmp (node A,node B){
	return A.mark>B.mark;
}

LL c[32],jj[32];

void chang(int i){
	int cnt=0;
	LL x=a[i].num;
	while (x>0){
		a[i].two[cnt++]=x%2;
		x/=2;
	}
	for (int j=0;j<cnt;j++) {
		c[j]+=(LL)(a[i].two[j]);
	}
}

int n,m;

int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf ("%lld",&a[i].num);
		chang(i);
	}
//	for (int i=1;i<=n;i++){
//		for (int j=0;j<=30;j++) cout<<a[i].two[j];
//		cout<<'\n';
//	}
//		
//	for (int i=0;i<=30;i++) cout<<c[i];
	int cnt=1;
	
	for (int i=0;i<=30;i++){
		if (c[i]>=m) jj[cnt++]=i;
	}
	
//	for (int i=1;i<cnt;i++) cout<<jj[i];
	
	for (int i=1;i<=n;i++){
		a[i].mark=0;
		for (int j=1;j<cnt;j++){
			a[i].mark+=myy[jj[j]]*(LL)(a[i].two[jj[j]]);
		} 
	}	

	sort (a+1,a+n+1,cmp);
	
//	for (int i=1;i<=n;i++) cout<<a[i].mark<<'\n';

	int ans=a[1].num;
	m--;
	cnt=2;
	while (m>0){
		ans=ans&a[cnt++].num;
		m--;
	}
	printf ("%d\n",ans);
	return 0;
}

