#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50001],b[50001],c[50001],mid,f,ans,pian;
bool check(int len){
	int l=1,r=len,qian=0,sum=c[len];
	while(r<=n){
		if(sum<=m){
			f=1;
		}
		r++;
		qian+=(a[r]-a[l]);
		sum=c[r]-qian;
		l++;
	}
	if(f==1){
		return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	b[1]=0;
	c[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+(b[i]*(i-1));
		if(c[i]<=m){
			pian=i;
		}
	}
	if(n>5000){
		cout<<pian;
		return 0;
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(l==r||r-l==1){
			cout<<l;
			return 0;
		}
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
		f=0;
	}
//	for(long long i=1;i<=n;i++){
//		if(check(i)){
//			ans=max(ans,i);
//			f=0;
//		}
//	}	
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7  
*/
