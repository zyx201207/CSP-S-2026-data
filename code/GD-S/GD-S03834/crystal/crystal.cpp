#include<bits/stdc++.h>
using namespace std;
int n;
long m,a[500000],dd=0;
int hc(long le,long ri,int c[]){//合成 
	if(ri==n)return ri-le;
	if(dd!=0){//时间 
		if(dd+c[ri]*(ri-le)>m){
			dd=0;
			return hc(le+1,ri+1,c);
		}else{
			dd=dd+c[ri]*(ri-le);
			return hc(le,ri+1,c);
		}
	}
	for(int i=le;i<=ri;i++){//计算次数 
		dd=dd+c[i]*(i-le);
		if(dd>m){
			dd=0;
			return hc(le+1,ri+1,c);
		}
	}
	return hc(le,ri+1,c);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int b[500000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	b[0]=a[0];
	for(int i=1;i<n;i++){//差分数组 
		b[i]=a[i]-a[i-1];
	}
	cout<<hc(0,0,b); 
	return 0;
} 
