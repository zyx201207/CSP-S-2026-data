#include<bits/stdc++.h>
using namespace std;

vector<long long> a;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	long long s;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s;
		a.push_back(s);
	}sort(a.begin(),a.end());
	long long b=0;
	for(int i=0;i<(n-m);i++){
		long long x=a[i];
		for(int j=i+1;j<i+m;j++)
			x=x&a[j];
		if(x>b) b=x;
	}cout<<b;
	
	/*
	fclose("and.in",stdin);
	fclose("and.out",stdout);
	*/
	return 0;
} 
