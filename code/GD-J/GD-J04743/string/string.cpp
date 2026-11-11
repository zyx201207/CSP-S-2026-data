#include<bits/stdc++.h>
using namespace std;
int n,sum=-1;
int main(){
	cin>>n;
	vector<int> a(n);
	vector<char> c(n);
	vector<char> str;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int k=0;k<a[i];k++){
			sum++;
			str.push_back(c[i]);
		}
	}
	int cnt=sum;
	bool b=1;
	for(int i=0;i<=sum;i++){
		if(str[i]!=str[cnt])
			b=0;
		cnt--;
	}
	if(b)	cout<<0;
	
	
}
