#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	vector <char> a;
	for(int i=0;i<n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=0;j<x;j++){
			a.push_back(y);
		}
	}
	int q=a.size();
	for(int i=0;i<q/2;i++){
		if(a[i]!=a[q-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
