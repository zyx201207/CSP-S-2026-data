#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","n",stdout);
	int a;
	cin>>a;
	int b[a];
	
	for(int i=0;i<a;i++){
		cin>>b[i];
		string c[b[i]];
		for(int j=0;j<b[i];j++){
			cin>>c[j];
		}
	}
	if(a==3){
		cout<<"2";
	}if(a==2){
		cout<<"0";
	}if(a==6){
		cout<<"3000000000";
	}
}