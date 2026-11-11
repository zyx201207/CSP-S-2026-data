#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0,m=0,mx=-10000000;
	cin>>n>>m;
	vector<long long> v(n);
	for(long long i=0;i<n;i++){
		cin>>v[i];
	}
	if(m==1){
		for(long long i=0;i<n;i++){
			if(v[i]>mx){
				mx=v[i];
			}
		}
		cout<<mx;
		return 0;
	}
	
	for(long long i=0;i<n-1;i++){
		for(long long j=i+1;j<n;j++){
			if((v[i]&v[j])>mx){
				mx=(v[i]&v[j]);
			}
		}
	}
	
	cout<<mx;
	return 0;
}

