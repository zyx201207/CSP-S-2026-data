#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,a[100001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	cout<<a[0];
	return 0;
}
