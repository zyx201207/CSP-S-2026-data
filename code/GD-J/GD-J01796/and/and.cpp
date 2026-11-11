#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],sum=0,maxn=0;
bool kp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,kp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i]&a[j];
				maxn=max(maxn,x);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		long long x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	if(m==n-1){
		bool b=false,bb=false;
		long long x=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[j]==a[i]&&b==false){
					b=true;
				}
				else{
					if(bb==false){
						x=a[j];
						bb=true;
					}
					else x&=a[j];
				}
			}
			maxn=max(maxn,x);
		}
		cout<<maxn;
		return 0;
	}
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
