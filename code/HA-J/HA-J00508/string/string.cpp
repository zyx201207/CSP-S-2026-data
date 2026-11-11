#include <bits/stdc++.h>
using namespace std;

int main(){
  	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	int sum_=0;
	while(n--){
		int x;
		char c;
		cin>>x>>c;
		for(int i=0;i<x;i++){
			s+=c;
			sum_++;
		}
	}
	s = ' '+s;
	
	
	int k=0;
	for(int i=1;i<=sum_/2;i++){
		if(s[i]!=s[sum_+1-i]){
			k++;
		}
	}
	cout<<k;
	
	
	
	/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
//	cout<<s<<endl<<sum_;
	 
	
	return 0;
} 
