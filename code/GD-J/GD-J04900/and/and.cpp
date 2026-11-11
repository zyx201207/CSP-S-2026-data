#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,maxx=0,cnt = 0,a[10001];
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		if(a[i]>maxx) maxx=a[i];
	}
	if(m==1) cout<<maxx;
	for(int i = 0;i<n;i++){
		cnt = a[i]&a[i+1];
	}
	return 0;
}
