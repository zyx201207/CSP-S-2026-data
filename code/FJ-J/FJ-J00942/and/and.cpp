#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,c=1;
bool flag=true,flaga=true;
int a[N],u[5];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4) flag=false;
		if(flag){
			u[a[i]]++;
		}
		if(a[i]!=i-1) flaga=false;
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
			if(sum==0){
				break;
			}
		}
		cout<<sum;
		return 0;
	}
	if(flag){
		int mx=-1,t=0;
		for(int i=1;i<=4;i++){
			if(u[i]>mx){
				t=i;
				mx=u[i];
			}
		}
		if(t==1){
			if(u[t]>=m){
				cout<<1;
			}else if(u[t]+u[3]>=m){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(t==2){
			if(u[t]>=m){
				cout<<2;
			}else if(u[t]+u[3]>=m){
				cout<<2;
			}else{
				cout<<0;
			}
		}else if(t==3){
			if(u[t]>=m){
				cout<<3;
			}else if(u[t]+u[2]>=m){
				cout<<2;
			}else if(u[t]+u[1]>=m){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			if(u[t]>=m){
				cout<<4;
			}else{
				cout<<0;
			}
		}
		return 0;
	}
	if(flaga){
		int c=1,o=pow(2,c);
		while(o<n){
			c++;
			o=pow(2,c);
		}
		o=pow(2,c-1);
		if(m<o){
			int sum=a[n];
			for(int i=2;i<=m;i++){
				sum=sum&a[n-i+1];
				if(sum==o){
					break;
				}
			}
			cout<<sum;
		}
		if(m==o){
			cout<<o;
		}
		if(m>o){
			cout<<0;
		}
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
}
