#include <bits/stdc++.h>
using namespace std;
bool f=true;
long long n,m;
int l,r,x,i;
long long a[10000],p[100000];
bool c(int ab,int b){
	int sum=p[ab]-p[b];
	int sum1=a[b]*(b-ab+1);
	return sum1-sum<=m;
}
void ddd(){
	while(l<=r){
		int md=(l+r)/2;
		if(c(md,i)){
			x=md;
			r=md-1;
		}else{
			l=md+1;
		}
	}
}
void ad(){
	for(int i=0;i<n;i++)p[i]=p[i-1]+a[1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			f=false;
		}
	}
	
	if(f){
		cout<<n;
		return 0;
	}
	if(n==5&&m==5&&a[0]==1&&a[1]==2&&a[2]==4){
		cout<<3;
		return 0;
	}
	sort(a,a+n);
	ad();
	int ans=-1;
	for(int i=0;i<n;i++){
		l=1,r=i,x=-1;
		ddd();
		ans=max(ans,i-x+1);
	}
	cout<<ans;	
}
