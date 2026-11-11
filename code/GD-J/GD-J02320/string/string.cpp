#include <iostream>
using namespace std;
int a[200005];
char b[200005];
string c;
int cnt;
int main(){
	fopen("string.cpp","string.in");
	fopen("string.cpp","string.out");
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c+=b[i];
		}
	}
	int l=0,r=c.size()-1;
	while(l<r){
		if(c[l]!=c[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
    }
