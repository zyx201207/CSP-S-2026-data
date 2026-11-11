#include<bits/stdc++.h>
#define int long long
using namespace std;
vector <long long> a(1000000000,0);
long long n;
long long t=0;
void d(long long b,long long c,long long e){
	if(e==0){
		t=max(t,c);
		return ;
	}
	for(long long i=n-b;i<=n-e;i++){
	    cout<<" "<<e<<":"<<i;		
	    d(i+1,c&a[i],e-1);
	    
	    

	}
	return;
}
signed main(){
	freopen('and.in','r',stdin);
	freopen('and.out','r',stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
		
	long long m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<=n-m;i++){
	    d(i+1,a[i],m-1);
	}
	cout<<t;
    return 1;
}
