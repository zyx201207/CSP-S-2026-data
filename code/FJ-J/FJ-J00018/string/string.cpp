#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,l;
	cin>>n;
	int la[n];
	char c[n];
	for (int i=0;i<n;i++){
		cin>>la[i]>>c[i];
		l+=la[i];
	}
	
	// Æ´½Ó
	char cz[l];
	int tmp=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<la[i];j++){
			cz[tmp] = c[i];
			tmp++;
		}
	} 
	
	int ans=0;
	for (int i=0;i<(l/2);i++){
		if (cz[i]-cz[l-i-1]!=0){
			ans++;
		}
	}
	
	cout<<ans;
	
	return 0;
}
