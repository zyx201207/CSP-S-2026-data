#include<bits/stdc++.h> 
using namespace std;
long long a[1000100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,num;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		num=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				num=max(a[i]&a[j],num);
			}
		}
		cout<<num;
		return 0;
	}
	if(n==m){
		num=a[1];
		for(int i=1;i<=n;i++){
			num=num&a[i];
		}
		cout<<num;
		return 0;
	}
	if(m==n-1){
		num=0;
		for(int i=1;i<=n;i++){
			int p=a[i];
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				p&a[j];
			}
			if(num<p){
				num=p;
			}
		}
		cout<<num;
		return 0;
	}
	num=a[n];
	for(int i=n;i>n-m;i--){
		num=a[i]&num;
	}
	cout<<num;
	return 0;
}
