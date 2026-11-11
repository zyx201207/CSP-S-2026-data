//GZ-J00290 南白初级中学 晏乾翔 
#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		long long ma=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i] & a[j];
				ma=max(ma,x);
			}
		}
		cout<<ma;
		return 0;
	}else if(m==1){
		long long ma=-1;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
		return 0;
	}else if(m==n){
		long long sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	return 0;
}

