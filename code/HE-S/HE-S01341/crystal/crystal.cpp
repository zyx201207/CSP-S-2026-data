#include<bits/stdc++.h> 
using namespace std;
long long n;

long long m,a[5000009],maxx,mid,ma,m1;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		mid=a[i];
		for(long long j=n-i+1;j>=0;j--){
			if(a[j]<=mid && (m-(mid-a[j]))>=0){
				m-=mid-a[j];
				ma++;
			}
		}
		maxx=max(ma,maxx);
		ma=0;
		m=m1;
	}
	cout<<maxx;
return 0;
}
