#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long l[1000000]={};




int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	if(m==1){
		sort(l,l+n);
		cout<<l[n-1];
		return 0;
	}else if(m==n){
		int xm=l[0];
		for(int i=1;i<n;i++){
			xm=xm&l[i];
		}
		cout<<xm;
		return 0;
	}else if(m==2){
	 	long long s=0;
		 for(int i=0;i<n;i++){
	 		for(int j=0;j<n;j++){
	 			s=max(s,(l[i]&l[j]));
			}
		}
		cout<<s;
		return 0;
	}else if(m==n-1){
		sort(l,l+n);
		int xm=l[1];
		for(int i=2;i<n;i++){
			xm=xm&l[i];
		}
		cout<<xm;
		return 0;
	}
	
	
	
	
	
	return 0;
}
