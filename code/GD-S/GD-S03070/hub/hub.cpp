#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t,u,k,v;
	cin>>c>>t;
	for(int i=0;i<t;i--){
		cin>>u;
		if(i=c-1){
			u=u;
		}
	}
	string a;
	int n,m,q=0,sum=0,hbr=0,wfj=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(n/2!=0){
		sum=a[n/2+1-1];
	}else{
		sum=a[n/2-1];
	}
	for(int i=0;i<n;i++){
		wfj=sum-a[i];
		if(a[i]<sum && wfj<m){
			hbr++;
			m=m-(sum-a[i]);
		}
	}
	cout<<hbr;
	cout<<u<<t;
	
	fclose(stdin);
	fclose(stdout);
} 
