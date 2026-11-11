#include<bits/stdc++.h>
using namespace std;
int a,n,sum;
string s,b; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	} 
	int l=0,r=s.size()-1;
	for(int i=1;i<=s.size()/2;i++){
		if(s[r]!=s[l]){
			sum++;
		}
			r--;
			l++;
	}
	cout<<sum;
}
