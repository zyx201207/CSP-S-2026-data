#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4){
			f=false;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(ans==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(f){
		long long n4=0;
		long long n3=0;
		long long n2=0;
		long long n1=0;
		long long n0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==4){
				n4++;
			}
			else if(a[i]==3){
				n3++;
			}
			else if(a[i]==2){
				n2++;
			}
			else if(a[i]==1){
				n1++;
			}
			else{
				n0++;
			}
		}
		if(n4>=m){
			cout<<4;
			return 0;
		}
		if(n3>=m){
			cout<<3;
			return 0;
		}
		if(n3+n2>=m){
			cout<<2;
			return 0;
		}
		if(n3+n1>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			long long sum=a[1];
			if(i==1){
				sum=a[2];
			}
			for(int j=1;j<=n;j++){
				if(j!=i){
					sum=sum&a[j];
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}
