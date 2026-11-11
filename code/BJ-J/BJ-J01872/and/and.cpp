#include <bits/stdc++.h>
using namespace std;
long long main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long>v;
    long long asdf;
    for(long long i = 0;i<n;i++){
		cin>>asdf;
		v.push_back(asdf);
	}
	for(long long i = 0;i<m-1;i++){
		long long l = v.size();
		for(long long j = 0;j<l;j++){
			for(long long k = j+1;k<l;k++){
				long long y = v[j]&v[k];
				v.push_back(y);
			}
			v.erase(v.begin());
		}
	}
	long long nmax = 0;
	long long l = v.size();
	for(long long j = 0;j<l;j++){
		nmax = max(nmax,v[j]);
	}
	cout<<nmax;
	return 0;
}
