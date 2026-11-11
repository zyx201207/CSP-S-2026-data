#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],mid,t;
bool check1(int p){
	for(int i=2;i<=n;i++){
		if(i>p){
			b[i]=b[i-1]+(a[i]-a[i-1])*(p-1)-(a[i-1]-a[i-p]);
		}else{
			b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
		}
	}
	for(int i=p;i<=n;i++){
		if(b[i]<=m){
			memset(b,0,sizeof(b));
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=0;
	int l=1,r=n;
	while(l<r){
		mid=(l+r)>>1;
		if(check1(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	int mid=(l+r-1)/2;
	cout<<mid<<endl;
	return 0;
}
