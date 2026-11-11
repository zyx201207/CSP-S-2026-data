#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,n,m;
	cin>>a>>n>>b>>m;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=1;i<=2;i++){
		if(n[i]=m[i]){
			cout<<"1";
		}
		else{
			for(int j=3-i;j>0;j--){
				cout<<"0";
				return 0;
			}
		}
		
	}
	cout<<"1";
	
	return 0;
}
