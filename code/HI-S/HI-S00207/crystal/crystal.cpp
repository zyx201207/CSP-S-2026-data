#include<bits/stdc++.h>
using namespace std;
vector<long long> c;
vector<long long> d;
long long n,m,r,res;

long long get_sum(){
	long long q=0;
	for(auto i:d){
		q+=i;
	}
	return q;
}

long long calc(long long k){
		long long p=m;
		d.clear();
		for(auto j:c){
			if(k-j<0){
				continue;
			}
			d.push_back(k-j);
		}
		sort(d.begin(),d.end());
		long long l=d.size();
		if(get_sum()<=p){
			r=max(r,l);
		}
		else{
			for(long long j=1;j<=l;j++){
			if(l<=r){
				break;
			}
			if(p-d[j-1]<0){
				r=max(r,j-1);
				break;
			}
			else{
				p-=d[j-1];
			}
		}
		}
		return r;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("ctystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	long long k;
	for(long long i=1;i<=n;i++){
		long long t;
		cin>>t;
		c.push_back(t);
	}
//	sort(c.begin(),c.end());
	for(auto i:c){
		res=max(r,calc(i));
	}
	cout<<r;
	return 0;
}

