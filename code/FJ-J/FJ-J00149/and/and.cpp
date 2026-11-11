#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long maa=0;
vector<long long> s;
long long solve(long long ma,vector<long long> a){
	for(long long i=ma;i>=0;i--){
		vector<long long> bites;
		//bites.resize(n+1);
		for(long long j=0;j<a.size();j++){
			if((a[j]/(1<<i))%2==1) bites.push_back(a[j]); 
		}
		if(bites.size()<m) continue;
		else return (1<<i)|solve(i-1,bites);
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	//s.resize(n+1);
	for(long long i=1;i<=n;i++){
		long long t;
		cin>>t;
		if(t!=0) maa=max(maa,(long long)log2(t));
		s.push_back(t);
	}
	cout<<solve(maa,s);
	return 0;
}
