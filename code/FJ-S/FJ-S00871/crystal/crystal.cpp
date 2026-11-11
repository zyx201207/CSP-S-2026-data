#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
long long ma=-1;
long long a[500050];
long long b[500010];
long long c[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n-1;i++){
		c[i]=c[i-1]+b[i];
	}
	long long l=1;
	long long r=1;
	while(r>=l){
		if(r==n){
			ma=max(ma,r-l);
			break;
		}
		if(s>m){
			s=s-(c[r-1]-c[l-1]);
			ma=max(ma,r-l);
			l++;
		}
		else{
			s=s+(r-l+1)*b[r];
			r++;
		} 
	}
	cout<<ma;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/