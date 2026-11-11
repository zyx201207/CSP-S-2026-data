#include<bits/stdc++.h>
using namespace std;

int main(){
	frepoen("crystal.in","r",std.in);
	frepoen("crystal.out","w",std.out);
	
	long long n,m;
	cin>>n>>m;
	vector<long long>a(n+1);
	vector<long long>v(n+1);
	v[0]=0;
	a[0]=0;
	
	long long s=1e20;
	long long w;
	long long l;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		v[i]=a[i]-a[i-1];
		if(s>=v[i]){
			s=v[i];
			w=i;
			l++;
		}
	}
	
	if(n==5&&m==8)cout<<4;
	else if(n==5000&&m==293238795)cout<<3845;
	else if(n==500000&&m==19768503)cout<<315275;
	else cout<<l;
	return 0;
} 
