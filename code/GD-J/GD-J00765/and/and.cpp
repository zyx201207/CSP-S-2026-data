#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0,max2n_1=0;
	bool txa=true;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		double x=log2(a[i]+1);
		int y=log2(a[i]+1);
		if(x-y!=0)txa=false;
		else max2n_1=max(max2n_1,a[i]);
	}
	sort(a,a+n);
	if(m==1)cout<<maxn;
	else if(txa)cout<<a[n-m];
	else if(m==n){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else cout<<max2n_1;
	return 0;
}
