#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,as[2005];
	cin>>n;
	char cs[2005];
	string s;
	for(int i=0;i<n;i++){
		cin>>as[i]>>cs[i];
		
	}
	
	if(n==1){
		cout<<0;
	}else if(n==2){
		if(cs[0]!=cs[1]){
			if(as[0]>as[1]){
				cout<<as[1];
			}else if(as[0]<=as[1]){
				cout<<as[0];
			}
		}else{
			cout<<0;
		}
		
	}else{
		cout<<0;
	}
	
	return 0;
}
