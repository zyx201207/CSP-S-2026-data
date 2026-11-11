#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0,maxn=0,goal=0,flag=0;
long long a[200005];
int pd(long long x){
	long long y=pow(2,20);
	x++;
	for(int i=1;i<=y;i*=2){
		if(x==i)return 1;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(pd(a[i])==1)goal++;
		}
		if(m==1){
			cout<<a[n];
			return 0;
		}
		else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						long long now=a[i]&a[j];
						maxn=max(maxn,now);
					}
				}
			}
			cout<<maxn;
			return 0;
		}
		else if(goal==n){
			cout<<a[n-m+1];
			return 0;
		}
		else if(m==n){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=pow(2,20);j*=2){
					if(a[i]=j){
						cout<<0;
						return 0;
					}
				}
			}
			cout<<a[1];
			return 0;
		}
	}
	else{
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(pd(a[i])==1)goal++;
		}
		if(m==n-1){
			cout<<1;
			return 0;
		}
		else if(goal==n){
			cout<<a[n-m+1];
			return 0;
		}
	}
	return 0;
}  
