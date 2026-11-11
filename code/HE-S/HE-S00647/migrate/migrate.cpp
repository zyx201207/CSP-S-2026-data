#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005];
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	bool ok=true;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])
				ok=false;
		cnt=a[i]-a[i-1];
	}
	if(ok){
		
	}
	
	return 0;
}
