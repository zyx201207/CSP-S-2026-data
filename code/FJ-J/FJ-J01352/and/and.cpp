#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0,mm,ma2=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
		if(i==1){
			
			mm=a[1];
		}else{
			mm=(mm&a[1]);
		}
		if(ma<a[i]){
			ma2=ma;
			ma=a[i];
		}
		
	}
	if(m==1){
		cout<<ma;
	}else if(m==n){
		cout<<mm;
	}else{
		cout<<ma2;
	} 
	
	return 0;
}
