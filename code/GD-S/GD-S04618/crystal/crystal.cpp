#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500001];
int b[500001];
bool re0(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,re0);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	int l=1,r=2;
	int tm=-1;
	long long hc=b[2];
	while(r>=l and r<=n){
		if(hc<=m){
			tm=max(tm,(r-l+1));
			r++;
			hc+=(r-l)*b[r];
		}else{
			l++;
			hc-=(a[r]-a[l]);
		}
	}
	cout<<tm;
	return 0;
}
