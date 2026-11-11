#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n,ans;
	cin>>n>>m;
	long long a[n+5];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=1;i<n;i++){
		long long j=i-1;
		long long w=a[j]*i;
		long long w2=a[i]*i;
		if(w2-w<=m){
			for(j;j>=0;j--){
				a[j]=a[i];
			}
			m-=w2-w;
			ans=i+1;			
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
