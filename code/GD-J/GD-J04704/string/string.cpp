#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<char> temp;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=0;i<a;i++) temp.push_back(c);
	}
	long long cnt=0;
	for(int i=0;i<temp.size()/2;i++){
		if(temp[i]!=temp[temp.size()-i-1]) cnt++;
	}
	cout<<cnt<<endl; 
	return 0;
} 
