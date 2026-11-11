#include <bits/stdc++.h>
using namespace std;
int a[20005];
string b[10005];
int main(){
	int n,sum=0;
	cin>>n;
	bool sy=true;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n-1;i++){
		if(b[i]!=b[i+1]){
			sy=false;
		}
		sum+=a[i];
	}
	if(sy){
		cout<<0;
	}
	else{
		cout<<sum/2;
	}
	return 0;
}
