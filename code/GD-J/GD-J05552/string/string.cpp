#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen('string.in','r',stdin);
	freopen('string.out','r',stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	vector <long long> a(1000000000,0);
	long long n1=0;
	for(long long i=0;i<n;i++){
		long long x;
		char x1;
		cin>>x>>x1;
		for(long long i=n1;i<n1+x;i++){
		    a[i]=x1-'a'+1;
		}
		n1+=x;
	}
	long long x,y;	
	long long t=0;
	for(long long i=0;i<n1;i++){
		x=i;
		y=n1-1-i;
		if (a[x]!=a[y]){
		    t++;
	    }
	}
	cout<<t;
	return 1;
}
