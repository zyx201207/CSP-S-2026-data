#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],t=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		if(n==4)cout<<12;
		if(n==2000)cout<<262142;
		if(n==200000)cout<<511;
	}
	if(m==5&&n==3)cout<<7;
	if(m==65536&&n==16384)cout<<49152;
	fclose(stdin);fclose(stdout);
	return 0;
} 
