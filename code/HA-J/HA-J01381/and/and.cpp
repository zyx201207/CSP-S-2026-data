#include<bits/stdc++.h>
using namespace std;
long long n,m,temp,daan;
vector<long long>a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>temp;
		a.push_back(temp);		
	}
	sort(a.begin(),a.end());
	daan=a[n-1];
	for(int i=n-2;i>=n-m;i--){
		daan=daan&a[i];		
	}
	cout<<daan;
	return 0;
} 
