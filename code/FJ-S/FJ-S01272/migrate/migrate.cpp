#include<bits/stdc++.h>
using namespace std;
long long arr[2000009],err[2000009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long t=0;
	cin>>t;
	long long op=0;
	while(t--){
		long long a=0,b=0;
		cin>>a>>b;
		for(long long i=1;i<=a;i++){
			cin>>arr[i];
		}
		sort(arr+1,arr+a+1);
		for(long long i=1;i<=a-3;i++){
			if((arr[i+2]-arr[i]<=b && arr[i+3]-arr[i+2]<=b)&& arr[i+3]-arr[i]>b){
				op++;
			}
		}
		cout<<op<<endl;
		op=0;
	}
	return 0;
}/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 
