#include<bits/stdc++.h>
using namespace std;
long long a[500002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000) sort(a+1,a+n+1);
	
	int ans=1;
	
	for(int i=n;i>=2;i--){
		if(ans>=i){
			break;
		}
		long long k=m;
		int aans=1;
		for(int j=i-1;j>=1&&k>=0;j--){
			if(k>0){
				k-=(a[i]-a[j]);
				aans++;
			}
			if(k<0){
				aans--;
				break;
			}
		}
		ans=max(ans,aans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
