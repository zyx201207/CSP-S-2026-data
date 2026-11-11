#include<bits/stdc++.h>
using namespace std;
vector<char> a;
vector<long long> b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long r,l=0,ans=0;
	cin>>r;
	for(long long i=0;i<r;i++){
		long long x;
		char y;
		cin>>x>>y;
		if(a.empty()){
			a.push_back(y);
			b.push_back(x);
		}
		else{
			if(y==a[a.size()-1]){
				b[b.size()-1]+=x;
			}
			else{
				a.push_back(y);
				b.push_back(x);
			}
		}
	}
	r=a.size()-1;
	while(l<r){
		if(a[l]!=a[r]){
			ans=ans+min(b[l],b[r]);
		}
		long long ls=min(b[r],b[l]);
		b[l]-=ls;
		b[r]-=ls;
		if(b[l]==0) l++;
		if(b[r]==0) r--;
	}
	cout<<ans;
	return 0;
} 
