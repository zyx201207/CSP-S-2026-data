#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string c;
	int k=0;
	int a[999]={};
	char b[999]={};
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[k]=b[i];
			k++;
		}
	}
	string d;
	k=0;
	for(int i=c.size()-1;i>=0;i--){
		d[k]=c[i];
	}
	bool f=true;
	for(int i=0;i<c.size();i++){
		if(c[i]!=d[i]){
			f=false;
			cout<<"2";
			return 0;
		}
	}
	if(f){
		cout<<"0";
	}
	return 0;
}
