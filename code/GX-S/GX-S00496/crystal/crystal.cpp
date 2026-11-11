#include<bits/stdc++.h>
using namespace std;
int n,qd,qdd,z[500005],num,dc,dcc;
long long m,mm,x[500005],y[500005],dcdc;
int px(int l,int r){
	if(l>=r) return 0;
	if(l+1==r){
		if(x[l]>x[r]){
			int s=x[l];
			x[l]=x[r];
			x[r]=s;
		}
		return 0;
	}
	int s=0,ll=l,rr=r;
	for(int i=1;ll!=rr;){
		if(x[ll]>x[rr]){
			s=x[ll];
			x[ll]=x[rr];
			x[rr]=s;
			i=(i+1)%2;
		}
		if(i){
			ll++;
		}else{
			rr--;
		}
	}
	px(l,ll-1);
	px(ll,r);
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	px(0,n-1);
	qd=1;
	dc=1;
	mm=0;
	dcdc=x[1]-x[0];
	for(int i=0;i<n;i++){
		if(x[i]!=i+1){
			qd=0;
			break;
		}
		mm+=i;
		if(mm<=m)qdd=i+1;
	}
	for(int i=2;i<n;i++){
		if(x[i]-x[i-1]!=x[i-1]-x[i-2]){
			dc=0;
			break;
		}
		dcdc+=(x[i]-x[i-1])*i;
		if(dcdc<=m)dcc=i+1;
	}
	if(qd){
		cout<<qdd;
	}else if(dc){
		cout<<dcc;
	}else{
		z[0]=1;
		z[1]=1;
		if(x[1]-x[0]<=m){
			z[1]=2;
			y[1]=x[1]-x[0];
			}
		for(int i=2;i<n;i++){
			if(y[i-1]+(x[i]-x[i-1])*z[i-1]<=m){
				z[i]=z[i-1]+1;
				y[i]=y[i-1]+(x[i]-x[i-1])*z[i-1];
			}
		}
		num=0;
		for(int i=0;i<n;i++){
			num=max(num,z[i]);
		}
		cout<<num;
	}
	return 0;
	
}
