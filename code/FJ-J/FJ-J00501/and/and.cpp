#include <bits/stdc++.h>
using namespace std;
long long n,m,minn;
long long s[1000005],d[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		s[i]=a;	
		minn=max(minn,s[i]);
	}
	for(long long i=0;i<n;i++){
		for(long long j=i;j<n;j++){
			minn=min(minn,min(i,j));
		} 
	}
	cout<<minn;
	return 0;
}
