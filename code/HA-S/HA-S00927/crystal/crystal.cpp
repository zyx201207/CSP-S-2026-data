#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;unsigned long long m;cin>>n>>m;
	long long a[n];for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=n;i>0;i--){
		long long s=9223372036854775807;
		for(int j=0;j<=n-i;j++){
			long long t=0;
			for(int l=j;l<i+j;l++)t+=a[i+j-1]-a[l];
			s=min(s,t);
		}if(s<=m){
			cout<<i;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
