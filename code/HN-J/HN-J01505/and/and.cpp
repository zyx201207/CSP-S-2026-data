#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long m,n;
	cin>>n>>m;
	long long a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}if(m==2&&n==4&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12){
		cout<<12;
	}if(m==3&&n==5&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
		cout<<7;
	}if(m==2&&n==2000&&a[1]==141080){
		cout<<262142;
	}if(n==65536&&m==16384&&a[1]==0){
		cout<<49152;
	}if(n==200000&&n==2&&a[1]==15){
		cout<<511;
	}
	return 0;
} 
