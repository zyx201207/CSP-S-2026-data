#include<bits/stdc++.h>
using namespace std;
int n,could;
long long m,nm[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>nm[i];
	}
	sort(nm,nm+n);
	for(int i=0;i<n;i++){
		if(nm[i+1]==nm[i]) continue;
		long long need=0;
		int can=1;
		for(int j=0;j<i;j++){
			need+=nm[i]-nm[j];
			can++;
		}
		int cant=0;
		while(need>m){
			need-=nm[i]-nm[cant++];
			can--;
		}
		could=max(could,can);
	}
	cout<<could;
	return 0;
}
