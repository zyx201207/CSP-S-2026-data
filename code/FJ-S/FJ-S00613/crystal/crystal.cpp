#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=5e5+10;
int n;
ll m;
int a[MAXN];
ll qzh[MAXN];
int ans;

bool cmp(int a,int b){
	return a<b;
}

int check(int x){
	int l=0,r=x-1,mid;
	int ret=1;
	while(l<=r){
		mid=(l+r)/2;
		int cst=(a[x]*(x-mid))-qzh[x-1];
		if(mid!=0) cst+=qzh[mid-1];
//		if(x==5) cout<<mid<<' '<<l<<' '<<r<<' '<<cst<<endl;
		if(cst<=m){
			ret=max(ret,x-mid+1);
			r=mid-1;
		}
		else l=mid+1;
	}
	return ret;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	qzh[0]=a[0];
	for(int i=1;i<n;i++) qzh[i]=qzh[i-1]+a[i];
	
	for(int i=0;i<n;i++){
		ans=max(ans,check(i));
//		cout<<check(i)<<' ';
	}
	cout<<ans<<endl;
	
	return 0;
}
