#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500005],s[500005]={},mx=-1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			s[i]+=a[j];
		}
	}
	if(s[n]==(a[1]+a[n])*n/2){
		for(int i=1;i<=n;i++){
			if(((a[1]+a[i-1])*i/2<=m)&&i>mx){
				mx=i;
			}
		}
		cout<<mx;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			long long sm=a[i]*(i-j+1)-(s[i]-s[j-1]);
			if(sm<=m&&(i-j+1)>mx){
				mx=(i-j+1);
				break;
			}
		}
	}
	cout<<mx;
	return 0;
} 
