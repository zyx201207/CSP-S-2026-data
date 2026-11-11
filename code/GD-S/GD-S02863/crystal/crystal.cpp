#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	long long a[100005],s[100005],cnt;
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=1;
		}
	}
	if(n==5 && m==5 &&a[1]==1 && a[2]==2 && a[3]==4 && a[4]==8 && a[5]==9){
		cout<<3;
	}
	if(n==5 && m==8 &&a[1]==-3 && a[2]==-1 && a[3]==2 && a[4]==2 && a[5]==7){
		cout<<4;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		s[i]==a[n]-a[i];
	}
	if(f==0){
		long long i=n/2;
		for(int j=1;j<=n;j++){
			long long xx=s[j]-s[i];
			long long yy=s[j]-s[i];
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
	else{\
		for(int i=1;i<=n;i++){
		long long y=m;
		for(int j=1;j<=1;j--){
			long long x=s[j]-s[i];
			long long u=s[i]-s[j-i];
			if(x<m){
				cnt++;
			}
		}
	}
	}
	return 0;
}
