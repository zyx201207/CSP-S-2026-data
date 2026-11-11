#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
int n,m,a[100000],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1) {
		cout<<a[n];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
