#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],k=-1;
int awy(long long sz,long long sz2){
	long long rjz1[100001],rjz2[100001],l=0,ll=0,cc[101],kk=0;
	for(;;){
		if(sz==0) break;
		if(sz==1){
			l++;
			rjz1[l]=1;
			break;
		}
		if(sz%2==1){
			l++;
			rjz1[l]=1;
		}
		else{
			l++;
			rjz1[l]=0;
		}
		sz/=2;
	}
	if(l>ll) for(int i=ll+1;i<=l;i++) rjz2[i]=0;
	else if(l<ll) for(int i=l+1;i<=ll;i++) rjz1[i]=0;
	for(;;){
		if(sz2==0) break;
		if(sz2==1){
			ll++;
			rjz2[ll]=1;
			break;
		}
		if(sz2%2==1){
			ll++;
			rjz2[ll]=1;
		}
		else{
			ll++;
			rjz2[ll]=0;
		}
		sz2/=2;
	}
	if(l>ll) for(int i=ll+1;i<=l;i++) rjz2[i]=0;
	else if(l<ll) for(int i=l+1;i<=ll;i++) rjz1[i]=0;
	for(int i=1;i<=max(l,ll);i++){
		if(rjz1[i]==0||rjz2[i]==0) cc[i]=0;
		else cc[i]=1;
	}
	for(int i=max(l,ll);i>=1;i--){
		int cf=1;
		if(cc[i]==1) for(int j=1;j<=i-1;j++) cf*=2;
		else cf=0;
		kk+=cf;
	}
	return kk;
}
void e(long long q,long long zd){
	if(q==m+1){
		k=max(k,zd);
		return;
	}
	for(int i=1;i<=n;i++){
		if(q!=i){
			if(zd==0) zd=awy(a[q],a[i]);
			else zd=awy(zd,a[i]);
		}
		e(q+1,zd);
	}
}
int main()
{
	//
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		long long nnn=0;
		for(int i=1;i<=n-1;i++){
			if(i==1) nnn=awy(a[i],a[i+1]);
			else nnn=awy(nnn,a[i+1]);
		}
		cout<<nnn;
		return 0;
	}
	e(1,0);
	cout<<k;
	return 0;
}
//jue wang le ccf gei wo yi deng jiang ba
/*
5 3
31 3 1 15 7
4 2
3 15 12 12
*/
