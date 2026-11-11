#include<bits/stdc++.h>

using namespace std;
long long n;
long long m,p;
int l=0;	
int ma=-3292;
long long  a[10000001];	

	
int main(){	

freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n>>m;
	p=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	 for(int j=2;j<=n;j++){
	 	int	 cnt=1;
	 	p=m;
	 	for(int k=1;k<j;k++){
	
	 		l=a[j]-a[k];
	 		if(l<=p){
	 			p-=l;
	 			cnt+=1;
	 		
			 }
			 else {
			 	continue;
			 }
		 }
		ma=max(ma,cnt);
		
	 }
	cout<<ma;


	  return 0;
} 

