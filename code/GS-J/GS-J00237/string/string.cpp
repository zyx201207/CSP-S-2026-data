#include<iostream>
using namespace std;
int main(){
	freopen("string .in","r",stdin);
	freopen("string .out","w",stdout);
	int n;
	cin>>n;
	string s[n];
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	int num=0;
	for(int i=0;i<n;i++){
		num+=a[i];
	}
	int g;
	g=num;
	for(int i=0;i< num/2;i++){
		if(s[i]==s[num-i]){
			g=g-s[i];
		}
	}
	cout<<g;
	return 0 ;
}
