#include<bits/stdc++.h>
using namespace std;
long long n,m[100000];
long long a;
long long s;
long long minn=999999;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	for(int i=0;i<n;i++){
		if(minn>m[i])a=i;
		minn=min(minn,m[i]);
	}
	m[a]=999999,minn=999999;
	for(int i=0;i<n;i++){
		if(minn>m[i])a=i;
		minn=min(minn,m[i]);
	}
	cout<<minn;
	
	return 0;
}
