#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,sum;
	bool p=true;
	int n;
	cin>>n;
	string o,u;
	cin>>a>>o;
	u=o;
	sum+=a;
	for(int i=1;i<n;i++){
		cin>>a>>o;
		sum+=a;
		if(u==o){
			continue;
		}else{
			u='0';
			p=false;
		}
	}
	if(p){
		cout<<0;
	}else{
		cout<<sum/2;
	}
	
	
	return 0;
}
