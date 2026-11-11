//GZ-S00275,刘睿羽,华东师范大学附属贵阳学校 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pis a[cz[i].x] 
#define pic a[cz[i].x+1] 
const int N=5e6+10; 
int n,m,maxn;
struct node{
	int x,k,z;
}a[N],cz[N];

bool cmp(node w1,node w2){
	return w1.x<w2.x;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].k=1;
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<n;i++){
	    cz[i].x=i,cz[i].k=a[i+1].x-a[i].x;
	}
	sort(cz+1,cz+n,cmp);
	
	for (int i=1;i<n;i++){
		if (pis.x==0x3f3f3f3f) continue;
	
		int spend=cz[i].k*pis.k+pis.z;
		if (spend>m) break;
		pis.z+=spend;
		pic.k+=pis.k;
		pis.x=0x3f3f3f3f;
	}
	for (int i=1;i<=n;i++){
		maxn=max(maxn,a[i].k);
	}
	cout<<maxn;
	return 0;
}   
