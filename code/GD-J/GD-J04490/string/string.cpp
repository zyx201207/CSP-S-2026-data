#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string g="\0";
	for(int i=0;i<n;i++){
		long long t;cin>>t;
		char c;cin>>c;
		for(long long j=0;j<t;j++){
			g+=c;
		}
	}
	long long sum=0;
	for(long long i=0;i<g.size()/2;i++){
		if(g[i]!=g[g.size()-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
