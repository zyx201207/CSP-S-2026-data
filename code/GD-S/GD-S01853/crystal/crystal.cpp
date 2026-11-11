#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int arr[x]={};
	for(int i=0;i<x;i++)cin>>arr[i];
	int n=arr[1]-arr[0];
	int a=0,b=0;
	while(1){
		a++;
		b+=a;
		if(b*n>y){
			cout<<min(a,x);
			return 0;
		}
	}fclose(stdin);
	fclose(stdout);
}
