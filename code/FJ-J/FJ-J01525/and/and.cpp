#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct afa{
	long long x,fa;
}a[200005];
bool cmp(afa a,afa b){
	if(a.x!=b.x){
		return a.x>b.x;
	}
	return a.fa<b.fa;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x;
		long long y=pow(2,ceil(log2(a[i].x)));
		if(y==a[i].x){
			a[i].fa=-1;
		}else{
			a[i].fa=y-a[i].x;
		}
	}
	
	sort(a+1,a+n+1,cmp);
	long long ans=a[1].x;
	for(long long i=2;i<=m;i++){
		while(a[i].fa==-1 && m<n && a[i+1].fa!=-1){
			m++;
		}
		ans&=a[i].x;	
	}
	cout<<ans;
	return 0;
}
