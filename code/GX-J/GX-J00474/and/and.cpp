#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long>a;
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		a.push_back(b);
	}
	sort(a.begin(),a.end());
	/*int k=0;
	for(int i=0;i<n-m+1;i++){
		int b=a[i];
		
		for(int j=0;j<m;j++){
			int x=a[i+j];
			b=b&x;
		}
		
		if(b>=k){
			k=b;
		}
	}
	cout<<k;*/
	int b=a[n-1];
	for(int i=n-1;i>=n-m;i--){
		b=b&a[i];
	}
	cout<<b;
	return 0;
}
