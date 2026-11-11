#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		long long sum=0;
		int gs=1;
		int j=i;
		while(j>=1 and sum*2+b[j]<=m){
			gs++;
			sum=sum*2+b[j];
			j--; 
		}
		ans=max(ans,gs);
	}
	cout<<ans;
	
	
	
	return 0;
} 
