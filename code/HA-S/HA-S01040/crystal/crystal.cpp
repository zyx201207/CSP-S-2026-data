#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n],b[n];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	long long s,x,y=0;
	for(long long i=1;i<=n;i++){
		b[i]=0;
		s=m;
		for(long long j=1;j<=n-i+1;j++){
			x=a[j]-a[i];
			if(x<=s){
				s-=x;
				b[i]++;
			}
		}
		if(y<b[i]) y=b[i];
	}
	cout<<y;
	return 0;
}
