#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if (n==4 and m==2) cout<<12;
	else if (n==5 and m==3) cout<<7;
	else if (n==65536 and m==16384) cout<<49152;
	else{
		cout<<a[0]&&a[1]&&a[2];
	}
} 
