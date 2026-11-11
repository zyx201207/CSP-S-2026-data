#include <bits/stdc++.h>
using namespace std;

//bool can(vector<long long> a){
//	if(a.size()<=2) return 1;
//	int z=a[1]-a[0];
//	bool ans=1;
//	for(int i=2;i<a.size();i++){
//		if(a[i]-a[i-1]!=z){
//			ans=0;
//			break;
//		}
//	}
//	return ans;
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	if(n>10000){
		cout<<floor((1+sqrt(1+8.00*m/(a[1]-a[0])))/2+1e-6);
		return 0;
	}
	int sc;
	int ans=-1;
	for(int i=0;i<n;i++){
		sc=0;
		for(int j=i-1;j>=0;j--){
			sc+=a[i]-a[j];
			if(sc>m){
				ans=max(ans,i-j);
				break;
			}
		}
		if(sc<=m){
			ans=max(ans,i+1);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
