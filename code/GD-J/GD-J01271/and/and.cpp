#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	long long sum=0;
	long long a[100001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int d=m;
	int ans=1;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m/2+m%2;j++){
			int x,y;
			x=a[ans];
			y=a[i];
			if(y==a[n]) ans+=1;
			if(x&y>sum){
				int f=x&y;
				sum=f;
			}
		}
		if(i==n){
			d=d/2+d%2-1;
			i-=d;
		}
	}
	cout<<sum;
}
