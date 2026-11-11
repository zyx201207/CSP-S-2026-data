#include<bits/stdc++.h>
using namespace std;
int n,t0,k,r;
long long m,a[100010],d[100010],b[100010],ans,as;
bool bg=1,xzB=1;
void b0(int r){
	if(d[r-1]!=0 && r-1!=1){
		t0++;
	}
	k=d[r];
	m-=k;
	if(m<0) bg=0;
	d[r]-=k;
	d[r-1]+=k;
	r=r-1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for(int i=3;i<=n;i++){
		if(!(d[i]==d[i-1])) xzB=0;
	}
	if(xzB){
		long long i=2; 
		ans++;
		while(m>=0){
			m-=a[i];
			ans++;
			i++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(d[i]==0){
			t0++;
		}
	}
	for(int i=2;i<=n;i++){
		if(d[i]>d[r]) r=i;
	}
	for(int i=2;i<=n;i++){
		if(d[i]<d[r]) r=i;
	}
	while(m>0){
		if(t0==n-1) break;
		else{
			if(d[r]!=0){
				b0(r);
				if(!bg){
					d[r]+=k;
					d[r-1]-=k;
				}	
			}else{
				if(r-1==1){
					b0(r+1);
					if(!bg){
						d[r]+=k;
						d[r-1]-=k;
					}
					r=r+1;
				}else{
					b0(r-1);
					if(!bg){
						d[r]+=k;
						d[r-1]-=k;
					}
					r=r-1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=d[i]+b[i-1];
	}
	for(int i=1;i<=n;i++){
		if(i==1) as++;
		else{
			if(b[i]==b[i-1]) as++;
			else{
				if(as>ans) ans=as;
				as=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
