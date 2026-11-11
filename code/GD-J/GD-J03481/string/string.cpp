#include <bits/stdc++.h>
using namespace std;
string a[200005];
string b[200005];
int n,ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		string x;
		cin>>m>>x;
		for(int j=0;j<m;j++){
			a[ans]=x;
			ans++;
		}
	}
	int s=0;
	for(int i=ans;i>=0;i--){
		b[s]=a[i];
		s++;
	}
	int sum=0;
	for(int i=0;i<=ans;i++){
		if(a[i]!=b[i]){
			sum++;
		}
	}
	cout<<sum/2;
	return 0;
} 
