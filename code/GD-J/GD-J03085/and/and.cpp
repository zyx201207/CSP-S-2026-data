#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
int num=pow(2,20)-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout <<sum;
		return 0;
	}
	else if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout <<mx;
		return 0;
	}
	else if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout <<mx;
		return 0;
	}
	else if(n<=20 && m<=20){
		for(int i=num;i>=0;i--){
			int sum=0;
			for(int j=1;j<=n;j++){
				if((a[j]^i)==(a[j]-i)){
					sum++;
				}
			}
			if(sum>=m){
				cout <<i;
				return 0;
			}
		}
	}
	else {
		for(int i=3;i>=0;i--){
			int sum=0;
			for(int j=1;j<=n;j++){
				if((a[j]^i)==(a[j]-i)){
					sum++;
				}
			}
			if(sum>=m){
				cout <<i;
				return 0;
			}
		}
	}
	return 0;
} 
