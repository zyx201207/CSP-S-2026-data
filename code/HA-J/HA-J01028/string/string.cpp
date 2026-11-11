#include<bits/stdc++.h>
using namespace std;
string s1,z1,s2,z2;
int sum,n,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>s2;
		for(int j=0;j<x;j++){
			s1+=s2;
		}
	}
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s1[s1.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
