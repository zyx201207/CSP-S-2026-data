#include<bits/stdc++.h>
using namespace std;
long long a[200001],maxx=0;
long long n,m;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	maxx=a[1];
	
	for(long long i=1;i<=m;i++){
	    maxx=maxx&a[i];
	}
	cout<<maxx;
	return 0;
}
