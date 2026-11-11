#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		long long _;
		cin>>_;
		a.push_back(_);
	}
	sort(a.begin(),a.end());
	long long mxid=0,mxm=0;
	for(long long i=0;i<n;i++){
		if(mxm>m)break;
		mxm+=i*(a[i]-a[mxid]);
		mxid=i;
		
	}	
	cout<<mxid;
	fclose(stdin);
	fclose(stdout);
} 
 
 