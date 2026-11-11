#include<bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m,cnt=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<=n;i++){
		cin>>a[i];	
	}
	if(a[0]==a[1] || a[1]==a[2] || a[2]==a[3] || a[3]==a[4] || a[n-1]==a[n]){
		cnt++;
	}
	if(a[0]-a[1]==m || a[1]-a[2]==m || a[n-1]-a[n]==m){
		cnt+=2;
	}
	if(a[0]-a[1]+a[0]-a[2]==m || a[1]-a[0]+a[1]-a[2]==m || a[2]-a[1]+a[2]-a[0]==m || a[n]-a[n-1]-a[n-2]==m){
		cnt+=3;
	}
	cout<<cnt;
	
	return 0;
} 
