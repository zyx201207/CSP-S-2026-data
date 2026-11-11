#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+1+n);
	long long ans=0;
	long long t=1;
	long long sum=0;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-t);
		while(sum>m){
			sum-=(a[i]-a[t]);
			t++;
		}
		ans=max(ans,i-t+1);
	}	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
