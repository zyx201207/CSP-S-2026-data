#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	vector<pair<int,char>> ar;
	vector<long long> v;
	for(int i=0;i<n;i++){
		int a;char c;
		cin>>a>>c;ar.emplace_back(a,c);
	}
	long long cnt=0,l=0;
	for(int i=0;i<n;i++){
		l+=ar[i].first;
		for(int j=1;j<=ar[i].first;j++)v.push_back(ar[i].second);
	}
	for(int i=0;i<l;i++){
		if(v[i]!=v[l-i-1])cnt++;
	}
	long long a=0,b=n-1,ans=0;
	cout<<cnt/2;
	
	return 0;
} 
