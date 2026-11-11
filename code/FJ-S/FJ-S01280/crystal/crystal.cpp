#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005]; 
long long MAX_crystal=-1e18;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long temp_m=m;
		long long temp_cnt=1;	
		for(long long j=i-1;j>=1;j--){
			temp_m-=a[i]-a[j];
			temp_cnt++;
			if(temp_m<=0) break;
		}
		if(temp_cnt>=MAX_crystal) MAX_crystal=temp_cnt;
	} 
	cout<<MAX_crystal<<endl;
	return 0;
}
