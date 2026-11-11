#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N],c[N],qca[N],qc[N];
long long m;
int n;
bool check(int j,int i){
	if(qca[i]-qca[j]-(qc[i]-qc[j])*(j-1)<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	qc[0]=c[0]=qca[0]=0;
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		qc[i]=qc[i-1]+c[i];
		qca[i]=qca[i-1]+c[i]*(i-1);
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
			}
			else l=mid+1;
		}
		int key=i-l+1;
		ans=max(ans,key);
	}
	cout<<ans;
	return 0;
}
