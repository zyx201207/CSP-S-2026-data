#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	string m;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			m+=b[i];
		}
	}
	long long f=m.size(),s=0;
	for(int i=0;i<f/2;i++){
		if(m[i]!=m[f-i-1]){
			s++;
		}
	}
	cout<<s;
	
	return 0;
}
