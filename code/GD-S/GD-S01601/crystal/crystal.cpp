#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//#define debug
#ifndef debug
ifstream fin("crystal.in");
ofstream fout("crystal.out");
#define cin fin
#define cout fout
#endif
int n;
ll m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	bool d_same=true;ll d;
	vector<ll>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==1)d=a[1]-a[0];
		if(i>1)if(a[i]-a[i-1]!=d)d_same=false;
	}
	if(d_same){
		if(d==0){cout<<n;return 0;}
		ll k=sqrt(m*2/d);
		while((k-1)*k/2*d<=m&&k<=n)k++;
		cout<<min<int>(k-1,n);return 0;
	}
	sort(a.begin(),a.end());
	int Max=0,f=0;ll sum=0;
	for(int b=1;b<n;b++){
		sum+=(b-f)*(a[b]-a[b-1]);
		while(sum>m){
			sum-=a[b]-a[f];
			f++;
		}
		Max=max(Max,b-f+1);
	}
	cout<<Max;
}
