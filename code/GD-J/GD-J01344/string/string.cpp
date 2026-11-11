#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
	int x,y,sum=0;
	char n;
	cin>>x;
	for(int i=0;i<x;i++){
		cin>>y>>n;
		for(int i=0;i<y;i++){
			s=s+n;
		}
	}
	int add=s.size()-1;
	for(int i=0;i<s.size()/2;i++){
		if(s[0]!=s[add]){
			sum++;
		}
		add--;
	}
	cout<<sum;
	return 0;
}

