#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long vec[200001];
	for(long long i=0;i<n;i++){
		long long a;
		cin>>a;
		vec[i]=a;
		for(long long j=0;j<n-1;j++){
			if(vec[i]>vec[i-1]){ 
				long long x=vec[i-1]; 
				vec[i-1]=vec[i];
				vec[i]=x;
			}
		}
	}
	long long ans=0;
	for(long long i=0;i<m-1;i++){
		long long p=vec[i];
		long long q=vec[i+1];
		ans=p&q;
	}
	cout<<ans;
	return 0;
}

