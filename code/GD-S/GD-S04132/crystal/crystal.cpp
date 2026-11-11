#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long cc=-0x3f3f3f3f,ans=0;
long long b[N];
long long a[N],n,m,t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		t=0;
		for(long long j=0;j<i;j++){
			t+=a[i]-a[j];	
		}
		if(t>=cc && t<=m){
			cc=t;
			ans=i+1;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
