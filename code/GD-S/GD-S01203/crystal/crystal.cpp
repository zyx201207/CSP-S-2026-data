#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=1e8)
	sort(a+1,a+1+n);
	long long x;
	long long v;
	long long l,r;
	long long cnt;
	if(n%2==1){
		x=n/2+1;
		v=a[x];
		l=n/2;
		r=n/2+2;
		cnt=1;
	}
	else{
		v=(a[n/2]+a[n/2+1])/2;
		l=n/2;
		r=n/2+1;
		cnt=0;
	}
	
	
	bool f=1;
	while(m){
		//cout<<"m=="<<m<<"\n";
		//cout<<abs(a[l]-v)<<" "<<l<<"\n";
		if(f==0)break;
		if(l>=1&&r<=n){
			if(m==0)break;
			if(f==0)break;
			while(abs(a[l]-v)<=abs(a[r]-v)&&l>=1){
				//cout<<"L\n";
				if(abs(a[l]-v)<=m){
					cnt++;
					m-=abs(a[l]-v);
					//cout<<l<<" "<<abs(a[l]-v)<<" "<<m<<" "<<cnt<<"\n";
				}
				else{
					f=0;
					break; 
				}
				l--;
			}
			if(f==0)break;
			//cout<<abs(a[r]-v)<<" "<<r<<"\n";
			while(abs(a[l]-v)>=abs(a[r]-v)&&r<=n){
				//cout<<"R\n";
				if(abs(a[r]-v)<=m){
					cnt++;
					m-=abs(a[r]-v);
					//cout<<r<<" "<<abs(a[r]-v)<<" "<<m<<" "<<cnt<<"\n";
				}
				else{
					f=0;
					break; 
				}
				r++;
			}
		}
		else if(l>=1){
			if(m==0)break;
			if(f==0)break;
			while(l>=1){
				//cout<<"L\n";
				if(abs(a[l]-v)<=m){
					cnt++;
					m-=abs(a[l]-v);
					//cout<<l<<" "<<abs(a[l]-v)<<" "<<m<<" "<<cnt<<"\n";
				}
				else{
					f=0;
					break; 
				}
				l--;
			}
			if(f==0)break;
		}
		else if(r<=n){
			if(m==0)break;
			if(f==0)break;
			//cout<<abs(a[r]-v)<<" "<<r<<"\n";
			while(r<=n){
				//cout<<"R\n";
				if(abs(a[r]-v)<=m){
					cnt++;
					m-=abs(a[r]-v);
					//cout<<r<<" "<<abs(a[r]-v)<<" "<<m<<" "<<cnt<<"\n";
				}
				else{
					f=0;
					break; 
				}
				r++;
			}
		}
		else{
			break;
		}
		
	}
	cout<<cnt;
	return 0;
} 
