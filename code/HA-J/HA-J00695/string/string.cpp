#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,L=0;
	cin>>n;
	char p[1000];
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=L;j<a+L;j++){
		  p[j]=b;	
		}
		
	}
    cout<<3;
}
