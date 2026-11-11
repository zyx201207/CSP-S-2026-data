#include<bits/stdc++.h>
using namespace std;
long long arr[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	int d=arr[2]-arr[1];
	int d1=0;
	int cnt=1;
	bool flag=1;
	while(d1<m){
		d1+=d*cnt;
		if(d1>m){
			cout<<cnt;
			flag=0;
		}
		else cnt++;
	}
	if(flag)cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

