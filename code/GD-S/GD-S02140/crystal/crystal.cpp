#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,ans=0;
	double pj;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pj+=a[i];
	}
	pj=(pj+m)/n;
	sort(a+1,a+1+n);
	long long int line;
	for(int i=1;i<=n;i++){
		if(a[i]>pj){
		    line=i-1;
			break;    
		}
	}
	//cout<<pj<<' '<<line;
	pj=0;
	for(int i=1;i<=line;i++){
	    pj+=a[i];	
	} 
	pj=(pj+m)/line;
	//cout<<pj<<' '<<line;
	for(int i=1;i<=line;i++){
	     if(a[i]>pj){
	     	break;
		 }
		 else{
		 	ans++;
		 }	
	}
	cout<<ans;
	return 0;
} 
