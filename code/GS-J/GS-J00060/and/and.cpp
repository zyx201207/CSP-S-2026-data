#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;

bool cmp(long long a,long long b){
	return a>=b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	long long a[N];
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m^5];
	
	return 0;
}

