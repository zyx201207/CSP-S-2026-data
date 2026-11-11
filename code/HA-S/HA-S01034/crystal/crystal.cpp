#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],c[500010],l,r,mid,e,d;
bool pq(int a,int b){
	return a>b;
}
bool work(int x){
	for(int i=1;i<=n-x+1;i++){
		e=c[i+x-1]-c[i]-(x-1)*b[i];
		if(e<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,pq);
	for(int i=1;i<=n;i++){
		b[i]=a[1]-a[i];
		c[i]=b[i]+c[i-1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<" ";
//	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++){
//		cout<<c[i]<<" ";
//	}
//	cout<<"\n";
	l=0,r=c[n];
	while(l<=r){
		mid=(l+r)>>1;
		if(work(mid)){
			d=max(d,mid);
//			cout<<"1:"<<l<<" "<<mid<<" "<<r<<"\n";
			l=mid+1;
		}else{
//			cout<<"0:"<<l<<" "<<mid<<" "<<r<<"\n";
			r=mid-1;
		}
	}
	cout<<d;
	return 0;
}
