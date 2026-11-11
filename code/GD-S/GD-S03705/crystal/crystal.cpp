#include<bits/stdc++.h>
using namespace std;
long long a[1000000000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long all=1;
	long long m1=m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long x=1;
	long long max=0;
	for(long long i=1;i<n;i++){
		while(true){
			m1-=a[i]-a[i-x];
			all++;
			if(m1<0){
				all--;
				break;
			}
			else if(i-x==0) break;
			else x++;
		}
		if(all>=max){
			max=all;
		}
		all=1;
		m1=m;
		x=1;
	}
	cout<<max;
	return 0;
		
}
