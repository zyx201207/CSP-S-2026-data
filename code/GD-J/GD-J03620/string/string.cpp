#include<bits/stdc++.h>
using namespace std;


int main(){
	
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s;
	int n;
	cin>>n;
	int num[300000];
	char spell[300000];
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>spell[i];
		l+=num[i];
	}
	int k=l; 
	
	
	
	fclose("string.in","r",stdin);
	fclose("string.out","w",stdout);
}
