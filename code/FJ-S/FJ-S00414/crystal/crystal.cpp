#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cha[500005],ans,f[10005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	bool isA=1,isB=1;
	long long ct=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) isA=0;
		if(i==2) ct=a[i]-a[i-1];
		if(i>2&&ct!=a[i]-a[i-1]){
			isB=0;
		}
	}
	if(isA||isB){
		ct=abs(ct);
		long long dt=sqrt(ct*ct*1+8*m*ct);
		cout<<min((dt-ct)/(2*ct)+1,n);
		return 0;
	}
	sort(a+1,a+n+1);
	long long m1=m;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			for(int c=m;c>=0;c--){ 
				if(c>=(a[i]-a[j]))
					f[c]=max(f[c],f[c-(a[i]-a[j])]+1);
				}
		}
	}
	long long mx=0;
	for(int i=1;i<=m;i++){
		mx=max(mx,f[i]);
	}
	cout<<mx;
	return 0;
}
