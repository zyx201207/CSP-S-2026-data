#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int num=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=num){
				num=a[i];
			}
		}
		cout<<num;
	}else if(m==2){
		int num=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>num){
					num=a[i]&a[j];
				}
			}
		}
		cout<<num;
	}else if(m==n){
		int num=a[1];
		for(int i=2;i<=n;i++){
			num=num&a[i];
		}
		cout<<num;
	}else if(m==n-1){
		int sum=99999;
		for(int i=1;i<=n;i++){
			if(a[i]<sum){
				sum=a[i];
			}
		}
		int num=0,p=0;
		if(a[1]!=sum){
			num=a[1];
			p=2;
		}else{
			num=a[2];
			p=3;
		}
		for(int i=p;i<=n;i++){
			if(a[i]!=sum){
				num=num&a[i];
			}
		}
		cout<<num;
	}else{
		int num=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			num=num&a[i];
		}
		cout<<num;
	}
	return 0;
}
