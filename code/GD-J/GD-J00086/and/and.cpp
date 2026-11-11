#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,mi=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i-1){
			mi++;
		}
	}
	
	if(m==n){
		int k=a[1];
		for(int i=2;i<=n;i++){
			k&=a[i];
		}
		cout<<k;
	}else if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]&a[j]>mx&&i!=j){
					mx=a[i]&a[j];
				}
			}
			
		}
		cout<<mx;
	}else if(m==1){
		int k=0;
		for(int i=1;i<=n;i++){
			k=max(k,a[i])
		}
		cout<<k;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-1];
	}
	return 0;
} 
