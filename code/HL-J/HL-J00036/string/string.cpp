#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[20000];
	char c[20000];
	vector<char> m(10);
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int l=0;
	for(int i=0;i<n;i++){
		l+=a[i]; 
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			m[i]=c[i];
		}
	}
	int count=0;
	for(int i=0;i<l;i++){
		if(m[i]==m[m.size()-i]){
			count+=0;
		}
		else{
			count+=1;
		}
	} 
	cout<<count;
	return 0;
}
