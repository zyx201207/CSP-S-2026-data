#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1],max=-1;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n-1;j++){
			if(a[i]&a[j]>max)max=a[i]&a[j];
		}
	}
	cout<<max;
	return 0;
}
