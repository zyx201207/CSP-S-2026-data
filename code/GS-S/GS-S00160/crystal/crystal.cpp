
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long r=0,r1=0;
	long long n,m;
	long long m1;
	cin>>n>>m;
	int a[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=a[0];i<=a[n-1]+m;i++){
		for(long long j=0;j<n;j++){
			if(a[j]<=i){
			m1+=i-a[j];
			r1++;
			}
		}
		if(m1<=m){
			if(r1>r)r=r1;
		}
		m1=0;
		r1=0;	
	}
	cout<<r<<endl;
	return 0;
}
