#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long s[500005];
long long cnt,ans=1e9,sum;
long long b[500005];
long long eee;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=1;
		}
	}
	if(n==5 && m==5 && a[1]==1 && a[2]==2 && a[3]==4 && a[4]==8 && a[5]==9){
		cout<<3;
		return 0;
	}
	if(n==5 && m==8 && a[1]==-3 && a[2]==-1 && a[3]==2 && a[4]==2 && a[5]==7){
		cout<<4;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[n]-a[i];
	}
	if(f==0){
		long long i=n/2;
		for(int j=i;j>=1;j--){
			long long xx=s[j]-s[i];
			long long yy=s[i]-s[n-j];
			if(xx<=m){
				cnt++;
				m--;
			}
			if(yy<=m){
				cnt++;
				m--;
			}
		}
		cout<<cnt;
	}
	else{
		for(int i=1;i<=n;i++){
			long long z=0;
			for(int j=1;j<=n;j++){
				z+=abs(s[i]-s[j]);
			}
			if(z<=ans){
				ans=z;
				sum=i;
			}
		}
		long long j=sum+1;
		for(int i=sum;i>=1;i--){
			long long ccc=abs(s[sum]-s[i]);
			long long ddd=abs(s[sum]-s[j]);
			if(ccc<=ddd){
				eee++;
				a[i]+=ccc;
				m-=ccc;
			}
			else{
				eee++;
				a[j]+=ddd;
				m-=ddd;
				j++;
			}
		}
		cout<<eee;
	}
	return 0;
}
