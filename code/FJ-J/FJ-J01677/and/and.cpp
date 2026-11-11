#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long b[200005];
long long c[35];
//kai long long
int main(){
	freopen("and.in","r",stdin);
//	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
	c[0]=1;for(long long i=1;i<=31;i++) c[i]=c[i-1]*2;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0,s,l=n,ll=0;
	for(long long i=31;i>=0;i--){
		s=0;
		for(long long j=1;j<=l;j++){
			if ((a[j]&c[i])!=0)s++;
		}
//		cout<<c[i]<<' '<<s<<endl;
//		for(long long j=1;j<=l;j++) cout<<a[j]<<' ';cout<<endl;
		if (s>=m){
			ll=0;
			for(long long j=1;j<=l;j++){
				if ((a[j]&c[i])!=0){ll++;b[ll]=a[j];}
			}
			l=ll;
			for(long long j=1;j<=l;j++){
				a[j]=b[j];
			}
			ans+=c[i];
		}
	}
	cout<<ans;
	return 0;
}
