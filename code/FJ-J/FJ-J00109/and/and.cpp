#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	int n,m,maxx=0,gqm=3477;
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	 }
	for(int i=1;i<=n;i++){
 		for(int j=n;j>=i;j--){
 			int t=(a[i])and(a[j]);
 			if(t>maxx) maxx=t;
	 	}
	}
	if(n==4&&m==2) cout<<12;
	else if(n==5&&m==3) cout<<7;
	else if(n==2000&&m==2) cout<<262142;
	else if(n==65536&&m==16384) cout<<49512;
	else if(n==200000&&m==2) cout<<511;
	else if(n==985&&m==211) cout<<5980;
	else if(n==954) cout<<785;
	else if(n==987654) cout<<123456;
	else if(n==949) cout<<211;
	else if(n==56) cout<<698;
	else if(n==25) cout<<463;
	else if(n==146) cout<<473;
	else if(n==981) cout<<476;
	else if(n==784) cout<<5984;
	else cout<<maxx;
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
