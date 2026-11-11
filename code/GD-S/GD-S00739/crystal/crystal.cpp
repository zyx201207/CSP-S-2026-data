#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[5005][5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long c=a[2]-a[1];
	bool f=1;
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=c)f=0;
	}
	if(f){
		long long numm=1;
		long long d[500005];
		for(long long i=1;i<=n;i++){
			if(m>=a[i]){
				m-=a[i];
				numm++;
			}
		}
		cout<<numm<<endl;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=n-i+1;j>1;j--){
				b[i][j]=b[i][j+1]+a[j]-a[j-1];
			}
		}
		long long cnt=0,ma=0;
		for(int i=1;i<n;i++){
			long long mm=m;
			for(int j=n-i+1;j>=1;j--){
			if(mm>=b[i][j]){
					mm-=b[i][j];
						cnt++;
				}
			}
			ma=max(ma,cnt);
			cnt=0;
		}
		cout<<ma<<endl;
		return 0;
	}
	return 0;
}
