#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long maxx;
int d(int x){
	int sum=0;
	int m1=m;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m1;j++){
			if(a[i]+j==x){
				sum++;
				m1-=j;
			}
		}
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(d(a[i])>maxx){
			maxx=d(a[i]);
		} 
	}
	cout<<maxx;
	return 0;
} 
