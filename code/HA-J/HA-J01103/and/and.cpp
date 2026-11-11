#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1]; return 0;
	}	
	int minn=99999999;
	for(int i=0;i<n;i++){
		minn=min(minn,a[i]);
	}
	cout<<minn;
	return 0;
}
