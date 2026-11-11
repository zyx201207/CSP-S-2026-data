#include<bits/stdc++.h>
using namespace std;
int n,d,x[1000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n;i++){
	       cin>>x[i];
	}
	int sf=x[2]-x[1];
	bool pan=true;
	for(int i=n;i<=2;i--){
		if(sf!=x[i]-x[i-1]){
			pan=false;
		}
	}
	if(pan==true){
		cout<<0;
	}else if(x[n]-x[1]<=10*d){
		int xx=x[n]-x[1]/d+1;
		int xy=1;
		for(int i=1;i<=xx;i++){
			xy*=i;
		}
		cout<<xy;
	}
	return 0;
}
		
